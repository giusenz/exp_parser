#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "rpn.h"
#include "sy.h"


int main(int argc, char *argv[]) {
// Check if the user provided an expression
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <infix expression>\n", argv[0]);
        fprintf(stderr, "Example: %s \"(\" 3 + 4 \")\" \"*\" 2\n", argv[0]);
        return 1;
    }

    // The infix tokens start at argv[1]. We can pass argv + 1 to the function.
    char **infix_tokens = argv + 1;
    int infix_size = argc - 1;

    printf("Infix expression: ");
    for(int i = 0; i < infix_size; i++) {
        printf("%s ", infix_tokens[i]);
    }
    printf("\n");

    // --- 1. CONVERT from Infix to RPN ---
    int rpn_size = 0;
    char **rpn_tokens = conversion(infix_tokens, infix_size, &rpn_size);

    printf("RPN expression:   ");
    for(int i = 0; i < rpn_size; i++) {
        printf("%s ", rpn_tokens[i]);
    }
    printf("\n");

    // --- 2. EVALUATE the resulting RPN expression ---
    double result = eval(rpn_tokens, rpn_size);
    printf("\nThe result is: %.2f\n", result);

    // --- 3. CLEAN UP the memory allocated by to_rpn ---
    for (int i = 0; i < rpn_size; i++) {
        free(rpn_tokens[i]); // Free each string
    }
    free(rpn_tokens); // Free the array itself

    return 0;

}

