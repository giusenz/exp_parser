/* This structure is used to manage tokens during the execution 
 * of the "Shunting Yard" algorithm (that is used to pass from regular notation 
 * to RPN notation) as well as in the final evaluation 
 * accomplished by the function eval() (see rpn.h). 
 * Here is why I decided to use a union type (strings U double) */


#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef enum {
    TYPE_DOUBLE,
    TYPE_STRING
} ItemType;

typedef union {
    double d_val;
    char *s_val;
} ItemValue;

typedef struct {
    ItemType type;
    ItemValue value;
} StackItem;

struct stackNode {
    StackItem data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

/* Basic stack operations needed */

void end(char *msg); //for debugging purposes

void push_double(StackNodePtr *topPtr, double value);
void push_string(StackNodePtr *topPtr, char *value);

StackItem pop(StackNodePtr *topPtr);

bool isEmpty(StackNodePtr topPtr);

void printStack(StackNodePtr currentPtr);

void destroyStack(StackNodePtr *topPtr);

#endif