#include <stdio.h>
#include <string.h>

#define MAX_SIZE 40
char stack[MAX_SIZE];
int top = -1;

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}

void push(char item)
{
    if (top >= MAX_SIZE - 1)
        printf("Stack overflow!\n");
    else
        stack[++top] = item;
}

int pop()
{
    int del;
    if (top >= 0)
    {
        del = stack[top--];
        return del;
    }
    return -1;
}

void get_prefix(char infix[50])
{
    char prefix[50], symbol;
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '+':
        case '*':
        case '/':
        case '-':
            while (precedence(symbol) < precedence(stack[top]))
                prefix[j++] = pop();
            push(symbol);
            break;

        case '^':
            while (precedence(symbol) <= precedence(stack[top]))
                prefix[j++] = pop();
            push(symbol);
            break;

        case ')':
            push(symbol);
            break;

        case '(':
            while (stack[top] != ')')
                prefix[j++] = pop();
            pop();
            break;

        default:
            prefix[j++] = infix[i];
            break;
        }
    }
    while (top >= 0)
        prefix[j++] = pop();
    prefix[j] = '\0';

    i = 0;
    while (prefix[i] != '\0')
        push(prefix[i++]);
    i = 0;
    while (top != -1)
        prefix[i++] = pop();
    prefix[i] = '\0';
    puts(prefix);
}

int main()
{
    int i = 0;
    char infix[50];
    printf("Enter the infix expression:\n");
    gets(infix);
    while (infix[i] != '\0')
    {
        push(infix[i++]);
    }
    i = 0;
    while (top != -1)
    {
        infix[i++] = pop();
    }
    printf("Prefix expression: ");
    get_prefix(infix);
    return 0;
}