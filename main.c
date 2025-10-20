#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "rpn.h"

int main(int argc, char *argv[]) {
    char* s[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    double test = eval(s,13);
    printf("The result is: %.2f\n", test);
    return 0;
}

