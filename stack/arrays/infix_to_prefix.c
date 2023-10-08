#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int top = -1;
int top_of_arr = -1;

enum type
{
    braces = 1,
    operator,
    operand,
    whitespace
};

enum levels
{
    one = 1,
    two,
    three
};

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

char stack[SIZE];

void push(char obj)
{
    if (top >= SIZE - 1)
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

void append(char *arr, int size, char element)
{
    if (top_of_arr < size)
    {
        top_of_arr++;
        arr[top_of_arr] = element;
        return;
    }
    printf("ERR: Array index out of bounds!\n");
    exit(-1);
}

int type_of(char symbol)
{
    switch (symbol)
    {
    case '\n':
        return whitespace;
    case '(':
    case ')':
        return braces;

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

int precedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return one;

    case '*':
    case '/':
        return two;

    case '^':
        return three;
    default:
        return -1;
    }
}

void print_arr(char *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%c ", arr[i]);
    printf("\n");
}

int main()
{
    char infix[100];
    char prefix[100];

    printf("Enter infix statement :\n");
    fgets(infix, 99, stdin);
    reverse(infix, strlen(infix));
    int i = 0;

    while (infix[i] != '\0')
    {
        char symbol = infix[i];
        switch (type_of(symbol))
        {
        case braces:
            if (symbol == ')')
            {
                push(symbol);
                break;
            }
            else
            {
                char del;
                while ((del = pop()) != ')')
                    append(prefix, 100, del);
            }
            break;

        case operator:
            while (top > -1 && precedence(stack[top]) > precedence(symbol))
                append(prefix, 100, pop());
            push(symbol);
            break;

        case operand:
            append(prefix, 100, symbol);
            break;
        }
        i++;
    }

    while (top > -1)
        append(prefix, 100, pop());
    reverse(prefix, top_of_arr);
    append(prefix, 100, '\0');

    printf("Prefix representation: ");
    print_arr(prefix, top_of_arr + 2);
    return 0;
}
