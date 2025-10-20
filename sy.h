#ifndef SY_H
#define SY_H

#include "stack.h"
#include "queue.h"
#include <ctype.h>

bool isNum(char *str);
int get_prec(char *op);
char **conversion(char *tokens[], int token_count, int *output_count);

#endif