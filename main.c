#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "rpn.h"
#include "sy.h"


int main(int argc, char *argv[]) {
    char **infix_tokens = argv + 1;
    int infix_size = argc - 1;
    int rpn_size = 0;
    char **rpn_tokens = conversion(infix_tokens, infix_size, &rpn_size);
    double res = eval(rpn_tokens,rpn_size);
    printf("The result is: %.2f\n", res);
    for (int i = 0; i < rpn_size; i++) {
        free(rpn_tokens[i]);
    } 
    free(rpn_tokens);
    return 0;
}

