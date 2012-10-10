/* Author: Aage Kvalnes <aage@cs.uit.no> */
#ifndef STACK_H
#define STACK_H

typedef struct stack_t stack_t;

stack_t *stack_create(void);
void stack_destroy(stack_t *s);
int stack_push(stack_t *s, void *item);
void *stack_pop(stack_t *s);

#endif  /* STACK_H */

