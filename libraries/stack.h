#ifndef __STACK_H__
#define __STACK_H__

#define T char //change this to stack datatype of choice
#define PRINT_TYPE "%c" //change this to match above data-type (with the quotes)

typedef struct stk stack;

stack *create_stack();
stack *delete_stack(stack *src);

void push(stack **destination, T item);
T pop(stack **src);

T stack_peek(stack *src);
int stack_is_empty(stack *src);
void print_stack(stack *src);

#endif