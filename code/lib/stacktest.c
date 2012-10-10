/* Author: Aage Kvalnes <aage@cs.uit.no> */
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void fatal_error(char *msg)
{
    printf(msg);
    exit(1);
}


int main(int argc, char *argv[])
{
    int retval;
    stack_t *s, *s2;

    printf("Creating new stack\n");
    s = stack_create();
    if (s == NULL) 
        fatal_error("Stack creation failed\n");

    printf("Pushing item onto stack\n");
    retval = stack_push(s, s);
    if (retval < 0)
        fatal_error("stack_push() failed\n");
    
    printf("Popping item from stack\n");
    s2 = stack_pop(s);
    if (s2 != s)
        fatal_error("stack pop did not return expected item\n");

    printf("Seems to work\n");
    return 0;
}
