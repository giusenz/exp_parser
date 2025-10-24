/* This structure is used only during the execution  
 * of the "Shunting Yard" algorithm, and it will only 
 * enqueue or dequeue strings,i.e the terminal input */

#ifndef QUEUE_H
#define QUEUE_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>


struct queueNode {
    char *data;
    struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

bool isQEmpty(QueueNodePtr headPtr);

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char *value);

char *dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);

#endif