#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define SIZE 100

char stack[MAX];
int top = -1;

enum type
{
    braces = 1, operator, operand };

void push(char obj)
{
    if (top > MAX)
    {
        printf("ERR: Stack overflow!\n");
        exit(-1);
    }
    top++;
    stack[top] = obj;
}

char pop()
{
    if (top < 0)
    {
        printf("ERR: Stack underflow!\n");
        exit(-1);
    }
    top--;
    return stack[top + 1];
}

int type_of(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '^':
        return operator;

    default:
        return operand;
    }
}

int evaluate(char symbol, int operand_1, int operand_2)
{
    switch (symbol)
    {
    case '+':
        return operand_2 + operand_1;

    case '-':
        return operand_2 - operand_1;

    case '*':
        return operand_2 * operand_1;

    case '/':
        return operand_2 / operand_1;

    case '^':
        return pow(operand_2, operand_1);

    default:
        printf("Invalid operator error!\n");
        exit(-1);
    }
}

int main(int argc, char *argv[])
{
    char postfix[SIZE];
    int result;

    printf("Enter postfix representation :");
    fgets(postfix, 99, stdin);

    int i = 0;
    char symbol;
    while ((symbol = postfix[i]) != '\0' && symbol != '\n')
    {
        switch (type_of(symbol))
        {
        case operator:
            push(evaluate(symbol, pop(), pop()));
            break;

        case operand:
            push(symbol);
            break;
        }
        i++;
    }

    printf("The evaluvation of the postfix expression %s is: %d\n", postfix, pop());
    return 0;
}