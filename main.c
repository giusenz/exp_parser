#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "rpn.h"
#include "sy.h"

/* Defining the type supported operators */
enum ops {
    PLUS = '+', SUB = '-', MULT = '*', DIV = '/'
};

bool isOp(char op) {
    switch (op) {
    case PLUS: return true;
    case SUB: return true;
    case MULT: return true;
    case DIV: return true;
    default: return false;
    }
}

bool hasOp(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isOp(str[i])) return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    // Check if the user provided an expression
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <infix expression>\n", argv[0]);
        fprintf(stderr, "Example: %s \"(\" 3 + 4 \")\" \"*\" 2\n", argv[0]);
        return 1;
    }    

    /* Check if the input format is the supported one, i.e. that every string of argv 
     * must not have a length > 1 in case there is an operator.
     * What is more, if there is the multiplication is not written an "*",
     * an error must be printed as well */
    
    for (int i = 1; i < argc; i++) {
        if ((strlen(argv[i])>1) && hasOp(argv[i]) ) {
            end("Invalid format.\nPlease add a space between each element of the expression");
        }
    }

    // The infix tokens start at argv[1]. We can pass argv + 1 to the function.
    char **infix_tokens = argv + 1;
    int infix_size = argc - 1;

    puts("+-+----------------------+-+");
    puts("Infix expression: ");
    for(int i = 0; i < infix_size; i++) {
        printf("%s ", infix_tokens[i]);
    }
    puts("\n");

    // --- 1. CONVERT from Infix to RPN ---
    int rpn_size = 0;
    char **rpn_tokens = conversion(infix_tokens, infix_size, &rpn_size);

    puts("RPN expression:   ");
    for(int i = 0; i < rpn_size; i++) {
        printf("%s ", rpn_tokens[i]);
    }
    puts("\n+-+----------------------+-+");

    // --- 2. EVALUATE the resulting RPN expression ---
    double result = eval(rpn_tokens, rpn_size);
    printf("The result is: %.2f\n", result);

    // --- 3. CLEAN UP the memory allocated by to_rpn ---
    for (int i = 0; i < rpn_size; i++) {
        free(rpn_tokens[i]); // Free each string
    }
    free(rpn_tokens); // Free the array itself

    return 0;

}

