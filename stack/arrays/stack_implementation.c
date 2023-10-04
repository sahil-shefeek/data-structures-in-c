#include <stdio.h>
#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(char obj)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("ERR: Stack overflow!\n");
        exit(-1);
    }
    top++;
    stack[top] = obj;
    printf("Succesfully pushed %d.\n", obj);
}

void pop()
{
    if (top < 0)
    {
        printf("ERR: Stack underflow!\n");
        exit(-1);
    }
    top--;
    printf("Succesfully popped %d.\n", stack[top + 1]);
}

void list()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Elements in the stack are:\n");
    for (int i = 0; i < top; i++)
        printf("%d\n", stack[i]);
}

int main(int argc, char *argv[])
{
    int choice, element;
get_choice:
    printf("Select operation:\n1. Push\n2. Pop\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter element to push:\n");
        scanf("%d", &element);
        push(element);
        list();
        break;

    case 2:
        pop();
        list();
        break;

    default:
        printf("Invalid operation!\n");
        goto get_choice;
    }
    return 0;
}