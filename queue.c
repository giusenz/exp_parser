#include "queue.h" 
#include "stack.h"

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char *value) {
    QueueNodePtr newPtr = malloc(sizeof(QueueNode));

    if (newPtr != NULL) {
        char *t = strdup(value);
        if (t == NULL) end("Insufficient memory");
        
        newPtr->data = t;
        newPtr->nextPtr = NULL;
        
        if (isQEmpty(*headPtr)) {
            *headPtr = newPtr;
        } 
        else {
            (*tailPtr)->nextPtr = newPtr;
        }
        *tailPtr = newPtr;
    } 
    else {
        end("Insufficient memory");
    }
}

char *dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
    char *value = (*headPtr)->data;
    QueueNodePtr tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    /* Case in which tha queue becomes empty */
    if (*headPtr == NULL) *tailPtr = NULL;

    free(tempPtr);
    return value;
}

bool isQEmpty(QueueNodePtr headPtr) {
    return headPtr == NULL;
}


