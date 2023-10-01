#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int top = -1;
enum type
{
    braces = 1, operator, operand };

enum levels
{
    one = 1,
    two,
    three
};

char stack[SIZE];

void push(char obj)
{
    if (top > SIZE)
    {
        printf("ERR: Stack overflow!\n");
        exit(0);
    }
    top++;
    stack[top] = obj;
}

char pop()
{
    if (top < 0)
    {
        printf("ERR: Stack underflow!\n");
        exit(0);
    }
    top--;
    return stack[top + 1];
}

void append(char *arr, int size, int *top, char element)
{
    if ((*top) < size)
    {
        (*top)++;
        arr[*top] = element;
        return;
    }
    printf("ERR: Array index out of bounds!\n");
    exit(0);
}

int type_of(char symbol)
{
    switch (symbol)
    {
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

int is_left_brace(char symbol)
{
    if (symbol == '(')
        return 1;
    else
        return 0;
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

int highest_precedence(char *arr, int size)
{
    int high = 0;

    for (int i = top; i >= 0; i--)
    {
        char symbol = arr[i];
        if (symbol == '(')
            break;
        int now = precedence(symbol);

        if (now != -1)
        {

            if (now > high)
                high = now;
        }
    }

    return high;
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
    char postfix[100];
    int pfix_top = -1;

    printf("Enter infix statement :\n");
    fgets(infix, 99, stdin);
    int i = 0;

    while (infix[i] != '\0' && infix[i] != '\n')
    {
        char symbol = infix[i];
        switch (type_of(symbol))
        {
        case braces:
            if (is_left_brace(symbol))
            {
                push(symbol);
                break;
            }
            else
            {
                while (1)
                {
                    char del = pop();
                    if (del == '(')
                        break;
                    else
                        append(postfix, 100, &pfix_top, del);
                }
            }
            break;

        case operator:
            while (top > -1 && highest_precedence(stack, SIZE) >= precedence(symbol))
                append(postfix, 100, &pfix_top, pop());
            push(symbol);
            break;

        case operand:
            append(postfix, 100, &pfix_top, symbol);
            break;
        }
        i++;
    }

    while (top > -1)
    {
        append(postfix, 100, &pfix_top, pop());
    }

    printf("Postfix representation: ");
    print_arr(postfix, pfix_top + 1);
    return 0;
}