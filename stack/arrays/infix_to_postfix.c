#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = -1;

void push(char obj)
{
    if (top >= STACK_SIZE - 1) {
        printf("ERR: Stack overflow!\n");
        exit(1);
    }
    top++;
    stack[top] = obj;
}

char pop()
{
    if (top < 0) {
        printf("ERR: Stack underflow!\n");
        exit(-1);
    }
    top--;
    return stack[top + 1];
}

int precedence(char ch)
{
    switch (ch) {
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

int main(int argc, char *argv[])
{
    char temp[2], buffer[BUFFER_SIZE], postfix[BUFFER_SIZE];
    temp[1] = '\0';
    printf("Enter infix expression:\n");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        if (*token == '+' || *token == '-' || *token == '*' || *token == '/' || *token == '^' ) {
            while (precedence(stack[top]) >= precedence(*token)) {
                temp[0] = pop();
                strncat(postfix, temp, BUFFER_SIZE - strlen(postfix) - 1);
            }
            push(*token);
        } else if (*token == '(') {
            push(*token);
        } else if (*token == ')') {
            while (top != -1) {
                temp[0] = pop();
                if (*temp == '(')
                    break;
                else
                    strncat(postfix, temp, BUFFER_SIZE - strlen(postfix) - 1);
            }
        } else {
            strncat(postfix, token, BUFFER_SIZE - strlen(postfix) - 1);
        }
        token = strtok(NULL, " ");
    }
    while (top != -1) {
        temp[0] = pop();
        strncat(postfix, temp, BUFFER_SIZE - strlen(postfix) - 1);
    }
    printf("Postfix expression: %s\n", postfix);

    return 0;
}