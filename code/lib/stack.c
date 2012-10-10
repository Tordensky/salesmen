/* Author: Aage Kvalnes <aage@cs.uit.no> */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAXNUM_STACK_ITEMS   16

struct stack_t
{
    int maxitems;
    int numitems;
    void **stack;
};

stack_t *stack_create(void)
{
    stack_t *s;

    s = malloc(sizeof(stack_t));
    if (s == NULL) {
        return NULL;
    }
    s->stack = malloc(sizeof(void*)*MAXNUM_STACK_ITEMS);
    if (s->stack == NULL)
        goto error;
        
    s->numitems = 0;
    s->maxitems = MAXNUM_STACK_ITEMS;

    return s;

 error:
    if (s != NULL)
        free(s);
    return NULL;
}


void stack_destroy(stack_t *s)
{
    free(s->stack);
    free(s);
}


int stack_push(stack_t *s, void *i)
{
    void *newstack;

    if (s->numitems >= s->maxitems) {
        /* Resize stack */
        newstack = realloc(s->stack, sizeof(void*)*(s->maxitems*2));
        if (newstack == NULL)
            return -1;
        s->maxitems *= 2;
        s->stack = newstack;
    }
    s->stack[s->numitems] = i;
    s->numitems += 1;
    return 0;
}

void *stack_pop(stack_t *s)
{
    if (s->numitems == 0)
        return NULL;
    s->numitems -= 1;
    return s->stack[s->numitems];
}
