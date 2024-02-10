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
        exit(1);
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

void reverse(char *str, size_t len)
{
    if (len > 0) {
        for (size_t i = 0, j = len - 1; i <= j; i++, j--) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
}

int main()
{
    char temp[2], buffer[BUFFER_SIZE], prefix[BUFFER_SIZE];
    temp[1] = '\0';
    printf("Enter infix expression:\n");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    reverse(buffer, strlen(buffer));
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
            while (top != -1 && precedence(stack[top]) > precedence(*token)) {
                temp[0] = pop();
                strncpy(prefix, temp, BUFFER_SIZE - strlen(prefix) - 1);
            }
            push(*token);
        } else if (*token == '^') {
            while (top != -1 && precedence(stack[top]) >= precedence(*token)) {
                temp[0] = pop();
                strncat(prefix, temp, BUFFER_SIZE - strlen(prefix) - 1);
            }
            push(*token);
        } else if (*token == ')') {
            push(*token);    
        } else if (*token == '(') {
            while (top != -1) {
                temp[0] = pop();
                if (*temp == ')')
                    break;
                else
                    strncat(prefix, temp, BUFFER_SIZE - strlen(prefix) - 1);
            }
        } else {
            strncpy(prefix, token, BUFFER_SIZE - strlen(prefix) - 1);
        }
        token = strtok(NULL, " ");
    }

    while (top != -1) {
        temp[0] = pop();
        strncat(prefix, temp, BUFFER_SIZE - strlen(prefix) - 1);
    }
    reverse(prefix, strlen(prefix));
    printf("Prefix expression: %s\n", prefix);
    return 0;
}