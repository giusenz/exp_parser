/* This program implements a simple stack that manages strings */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"  

void end(char *msg) {
    perror(msg);
    exit(1);
}

void push_double(StackNodePtr *topPtr, double value) {
    StackNodePtr newPtr = malloc(sizeof(StackNode));

    if (newPtr == NULL) end("Insufficient memory");

    newPtr->data.type = TYPE_DOUBLE;
    newPtr->data.value.d_val = value;
    
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
}

void push_string(StackNodePtr *topPtr, char *value) {
    StackNodePtr newPtr = malloc(sizeof(StackNode));

    if (newPtr == NULL) end("Insufficient memory");

    newPtr->data.type = TYPE_STRING;
    newPtr->data.value.s_val = strdup(value);
    if (newPtr->data.value.s_val == NULL) end("Insufficient memory");

    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
}

StackItem pop(StackNodePtr *topPtr) {
    StackNodePtr tempPtr = *topPtr;
    StackItem popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

bool isEmpty(StackNodePtr topPtr) {
    return topPtr == NULL;
}

void printStack(StackNodePtr currentPtr) {
    if (currentPtr == NULL) {
        puts("The stack is empty");
    } else {
        puts("The stack is: ");
        while (currentPtr != NULL) {
            if (currentPtr->data.type == TYPE_DOUBLE) {
                printf("%f --> ", currentPtr->data.value.d_val);
            } else if (currentPtr->data.type == TYPE_STRING) {
                printf("\"%s\", --> ", currentPtr->data.value.s_val);
            }
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL\n");
    }
}

void destroyStack(StackNodePtr *topPtr) {
    while (!(isEmpty(*topPtr))) {
        StackItem item = pop(topPtr);
        if (item.type == TYPE_STRING) {
            free(item.value.s_val);
        }
    }
}
