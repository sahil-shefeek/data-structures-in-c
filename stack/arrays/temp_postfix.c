#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 40

int stack[MAX_SIZE];
int top = -1;
char postfix[50];

int pop()
{
    int del = stack[top--];
    return del;
}

void push(int item)
{
    stack[++top] = item;
}

void postfix_eval()
{
    int result, i, x, y, val;
    for (i = 0; i < strlen(postfix); i++)
    {
        if ((65 <= postfix[i] && postfix[i] <= 90) || (97 <= postfix[i] && postfix[i] <= 122))
        {
            printf("Enter the value of %c: ", postfix[i]);
            scanf("%d", &val);
            push(val);
        }
        else
        {
            int y = pop();
            int x = pop();
            switch (postfix[i])
            {
            case '+':
                push(x + y);
                break;
            case '-':
                push(x - y);
                break;
            case '*':
                push(x * y);
                break;
            case '/':
                push(x / y);
                break;
            case '^':
                push(pow(x, y));
                break;
            }
        }
    }
    result = pop();
    printf("Result is %d\n", result);
}

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
void get_postfix(char infix[50])
{
    char symbol;
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
            while (precedence(symbol) <= precedence((char)stack[top]))
                postfix[j++] = pop();
            push(symbol);
            break;
        case '^':
            while (precedence(symbol) < precedence((char)stack[top]))
                postfix[j] = (char)pop();
            push(symbol);
            break;
        case '(':
            push(symbol);
            break;
        case ')':
            while (stack[top] != '(')
                postfix[j++] = (char)pop();
            pop();
            break;
        default:
            postfix[j++] = infix[i];
            break;
        }
    }
    while (top >= 0)
        postfix[j++] = (char)pop();
    postfix[j] = '\0';
    puts(postfix);
}

int main()
{
    char infix[50];
    printf("Enter the infix expression:\n");
    gets(infix);
    printf("Postfix expression: ");
    get_postfix(infix);
    postfix_eval();
    return 0;
}