#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "rpn.h"

int isOperator(char s[0]) {
    if (s == NULL || s[1] != '\0') {
        return 0; 
    }

    switch (s[0]) {
        case '+':
            return 1;
        case '-':
            return 2;
        case '*':
            return 3;
        case '/':
            return 4;
        default:
            return 0; 
    }
}

double eval(char *tokens[], int tokensSize) {
    StackNodePtr stackPtr = NULL;
    for (int i = 0; i < tokensSize; i++) {
        if (isOperator(tokens[i]) == 0) push_double(&stackPtr,atof(tokens[i]));
        else {
            /* Controlling the last two popped elements */
            StackItem p_second = pop(&stackPtr);
            StackItem p_first = pop(&stackPtr);

            double op2 = p_second.value.d_val;
            double op1 = p_first.value.d_val;

            int cmp = isOperator(tokens[i]);

            switch (cmp) {
                case 1: push_double(&stackPtr,op2+op1); break;
                case 2: push_double(&stackPtr,op1-op2); break;
                case 3: push_double(&stackPtr,op2*op1); break;
                case 4: push_double(&stackPtr,op1/op2); break;
            }
        }
    }
    double res = pop(&stackPtr).value.d_val;
    destroyStack(&stackPtr);
    return res;
}