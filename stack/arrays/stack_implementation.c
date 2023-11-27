#include <stdio.h>
#define MAX_SIZE 5

int top = -1;
int stack[MAX_SIZE];

void push(char obj)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("ERR: Stack overflow!\n\n");
        return;
    }
    top++;
    stack[top] = obj;
    printf("Succesfully pushed %d\n\n", obj);
}

void pop()
{
    if (top < 0)
        printf("ERR: Stack underflow!\n\n");
    else
    {
        printf("Succesfully popped %d\n\n", stack[top]);
        top--;
    }
}

void list()
{
    if (top == -1)
        printf("Stack is empty!\n\n");
    else
    {
        printf("Elements in the stack are:\n");
        for (int i = 0; i <= top; i++)
            printf("%d\n", stack[i]);
    }
}

int main(int argc, char *argv[])
{
    int choice, element;
    while (1)
    {
        printf("Select operation:\n1. Push\n2. Pop\n3. List\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push:\n");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            pop();
            break;

        case 3:
            list();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid operation!\n");
        }
    }
    return 0;
}