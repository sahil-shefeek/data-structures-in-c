#ifndef __STACK_H__
#define __STACK_H__

/**
 * @file stack.h
 * @brief Header file for a basic stack implementation using linked list.
 */

/**
 * @typedef T
 * @brief Data type for the stack elements.
 * Change this typedef to the desired stack data type.
 */
#define T char //change this to stack datatype of choice

/**
 * @def PRINT_TYPE
 * @brief Format specifier for printing elements of type T.
 * Change this to match the above data-type (with the quotes).
 */
#define PRINT_TYPE "%c" //change this to match above data-type (with the quotes)

/**
 * @struct stk
 * @brief Structure representing a stack.
 */
typedef struct stk stack;

/**
 * @brief Creates a new stack.
 * @return Pointer to the newly created stack.
 */
stack *create_stack();

/**
 * @brief Deletes a stack and frees memory.
 * @param src Pointer to the stack to be deleted.
 */
void *delete_stack(stack **src);

/**
 * @brief Pushes an element onto the stack.
 * @param destination Pointer to the stack where the element will be pushed.
 * @param item Element to be pushed onto the stack.
 */
void push(stack *destination, T item);

/**
 * @brief Pops the top element from the stack.
 * @param src Pointer to the stack to pop from.
 * @return The popped element.
 */
T pop(stack *src);

/**
 * @brief Returns the top element of the stack without removing it.
 * @param src Pointer to the stack.
 * @return The top element of the stack.
 */
T stack_peek(stack *src);

/**
 * @brief Checks if the stack is empty.
 * @param src Pointer to the stack.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int stack_is_empty(stack *src);

/**
 * @brief Prints the elements of the stack from top to bottom.
 * @param src Pointer to the stack.
 */
void print_stack(stack *src);

#endif