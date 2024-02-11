#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node 
{
    T data;
    struct node *next;
} node_t;

typedef struct stk
{
    node_t *head;
} stack;

stack *create_stack()
{
    stack *new_stack = (stack*) malloc(sizeof(stack));
    if(new_stack == NULL) {
        printf("ERR: Unable to allocate memory, Aborting...\n"
                "Failed stack creation\n");
        exit(1);
    }    
    new_stack->head = NULL;
    return new_stack;
}

stack *delete_stack(stack *src)
{
    while(src->head != NULL) {
        node_t *temp = src->head;
        src->head = src->head->next;
        free(temp);
    }
    free(src);
    return NULL;
}

void push(stack **destination, T item)
{
    node_t *new = (node_t *) malloc(sizeof(node_t));
    if(new == NULL) {
        printf("ERR: Unable to allocate memory, Aborting...\n"
                "Failed push(%d)\n", item);
        exit(1);
    } 
    new->data = item;
    new->next = (*destination)->head;
    (*destination)->head = new; 
}

T pop(stack **src)
{
    if((*src)->head != NULL) {
        node_t *temp = (*src)->head;
        T deleted = temp->data;
        (*src)->head = (*src)->head->next;
        free(temp);
        return deleted;
    } else {
        printf("Stack is empty!\n");
    }
}

T stack_peek(stack *src)
{
    if(src->head != NULL)
        return src->head->data;
}

int stack_is_empty(stack *src)
{
    if (src->head == NULL)
        return 1;
    return 0;
}

void print_stack(stack *src)
{
    if(src->head == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack [Top --- Bottom]: ");
        node_t* temp = src->head;
        while(temp != NULL) {
            printf(PRINT_TYPE"    ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
