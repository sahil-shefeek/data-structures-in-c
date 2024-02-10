#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 100
#define STACK_SIZE 100

double stack[STACK_SIZE];
int top = -1;

void push(double obj)
{
    if (top >= STACK_SIZE - 1) {
        printf("ERR: Stack overflow!\n");
        exit(1);
    }
    top++;
    stack[top] = obj;
}

double pop()
{
    if (top < 0) {
        printf("ERR: Stack underflow!\n");
        exit(-1);
    }
    top--;
    return stack[top + 1];
}

double evaluate(char* op, double operand_2, double operand_1)
{
    switch (*op)
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
        return pow(operand_1, operand_2);

    default:
        printf("Invalid operator error!\n");
        exit(1);
    }
}

int main()
{
    char buffer[BUFFER_SIZE];
    printf("Enter postfix expression: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        if (*token == '+' || *token == '-' || *token == '*' || *token == '/' || *token == '^') {
            push(evaluate(token, pop(), pop()));
        } else {
            push(strtod(token, NULL));
        }
        token = strtok(NULL, " ");
    }
    
    printf("The evaluvation of the postfix expression is: %lf\n", pop());
    return 0;
}