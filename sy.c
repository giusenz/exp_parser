/* The extent of this program is to convert the terminal input 
 * written in standard mathematical notation into Reverse Polish Notation */

/* From INFIX expression to POSTFIX expression */

#include "sy.h"

/* I need to return a simple array of strings (see rpn.c) */

bool isNum(char *str) {
    if (str == NULL || *str == '\0') return false;
    char *end;
    strtod(str, &end);
    return *end == '\0';
}

int get_prec(char *op) {
    if (op == NULL || op[1] != '\0') return 0;
    switch (op[0]) {
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

char **conversion(char *tokens[], int token_count, int *output_count) {
    StackNodePtr op_stack = NULL;
    QueueNodePtr output_head = NULL;
    QueueNodePtr output_tail = NULL;
    int rpn_token_count = 0;

    for (int i = 0; i < token_count; i++) {
        char *token = tokens[i];
        /* The token is a NUMBER */
        if (isNum(token)) {
            enqueue(&output_head,&output_tail,token);
            rpn_token_count++;
        }
        /* The token is an OPERATOR */
        else if (get_prec(token) > 0) {
            while (!isEmpty(op_stack) && strcmp(op_stack->data.value.s_val,"(") != 0 
            && get_prec(token) <= get_prec(op_stack->data.value.s_val)) {
                StackItem item = pop(&op_stack);
                enqueue(&output_head,&output_tail,item.value.s_val);
                rpn_token_count++;
                free(item.value.s_val);
            }
            push_string(&op_stack,token);
        }
        /* The token is a LEFT PARENTHESIS */
        else if (strcmp(token,"(") == 0) {
            push_string(&op_stack,token);
        }
        /* The token is a RIGHT PARENTHESIS */
        else if (strcmp(token,")") == 0) {
            while (!isEmpty(op_stack) 
            && strcmp(op_stack->data.value.s_val,"(") != 0) {
                StackItem item = pop(&op_stack);
                enqueue(&output_head, &output_tail, item.value.s_val);
                rpn_token_count++;
                free(item.value.s_val);
            }
            /* Discard the remaining parenthesis */
            if (!isEmpty(op_stack)) {
                StackItem paren = pop(&op_stack);
                free(paren.value.s_val);
             } 
            else {
                end("Mismatched closing parenthesis.\n");
            }
        } 
    }
    /* Empty the remaining operators from the stack to the queue */
    while (!isEmpty(op_stack)) {
        StackItem item = pop(&op_stack);
        enqueue(&output_head,&output_tail,item.value.s_val);
        rpn_token_count++;
        free(item.value.s_val);
    }
    
    /* "Formatting" the queue into the input needed for rpn */
    char **bridge = malloc(rpn_token_count*sizeof(char*));
    if (!bridge) end("Insufficient memory");

    for (int i = 0; i < rpn_token_count; i++) {
        bridge[i] = dequeue(&output_head,&output_tail); 
    }
    *output_count = rpn_token_count;
    return bridge;
}   