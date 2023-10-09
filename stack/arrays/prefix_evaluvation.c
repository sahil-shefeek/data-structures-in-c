#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define SIZE 100

int stack[MAX_SIZE];
int top = -1;

enum type
{
    braces = 1,
    operator,
    operand,
    whitespace
};

void push(int obj)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("ERR: Stack overflow!\n");
        exit(-1);
    }
    top++;
    stack[top] = obj;
}

int pop()
{
    if (top < 0)
    {
        printf("ERR: Stack underflow!\n");
        exit(-1);
    }
    int del = stack[top];
    top--;
    return del;
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
    case ' ':
    case '\n':
        return whitespace;
    default:
        return operand;
    }
}

void reverse(char *str, int len)
{
    int i = 0, temp;
    len = strlen(str);

    while (i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        i++;
    }
}

int raise(int base, int exponent)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

int evaluate(char symbol, int operand_1, int operand_2)
{
    switch (symbol)
    {
    case '+':
        return operand_1 + operand_2;

    case '-':
        return operand_1 - operand_2;

    case '*':
        return operand_1 * operand_2;
    case '/':
        return operand_1 / operand_2;

    case '^':
        return raise(operand_1, operand_2);

    default:
        printf("Invalid operator error!\n");
        exit(-1);
    }
}

int int_of(char num)
{
    if (num >= '0' && num <= '9')
        return num - '0';

    else
    {
        printf("Character '%c' is not a digit.\n", num);
        exit(-1);
    }
}

int main(int argc, char *argv[])
{
    char prefix[SIZE];
    printf("Enter prefix representation :");
    fgets(prefix, 99, stdin);
    printf("You have entered: %s\n", prefix);
    reverse(prefix, strlen(prefix));

    int i = 0;
    char symbol;
    while ((symbol = prefix[i]) != '\0' && symbol != '\n')
    {
        switch (type_of(symbol))
        {
        case operator:
            push(evaluate(symbol, pop(), pop()));
            break;

        case operand:
            push(int_of(symbol));
            break;
        }
        i++;
    }

    printf("The evaluvation of the prefix expression is: %d\n", pop());

    return 0;
}