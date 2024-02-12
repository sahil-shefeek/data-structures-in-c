#include <stdio.h>
#include <string.h>
#include "../libraries/stack.h"

#define BUFFERSIZE 100

int is_pair(char opening_brace, char closing_brace) {
    if (opening_brace == '(' && closing_brace == ')')
        return 1;
    else if (opening_brace == '[' && closing_brace == ']')
        return 1;
    else if (opening_brace == '{' && closing_brace == '}')
        return 1;
    return 0;
}

int validate_braces(char *expression, size_t expression_len)
{
    stack *mystack = create_stack();
    char *token = strtok(expression, " ");
    while (token != NULL) {
        switch (*token)
        {
        case '(':
        case '[':
        case '{':
            push(mystack, *token);
            break;

        case ')':
        case ']':
        case '}':
            if (is_pair(stack_peek(mystack), *token) == 1)
                pop(mystack);
            else
                return 0;
            break;
        }
        token = strtok(NULL, " ");
    }
    int result = stack_is_empty(mystack);
    delete_stack(&mystack);
    return result;
}

int main()
{
    char buffer[BUFFERSIZE];
    printf("Enter expression\n[Note : Terms must be space separeted!]\n");
    fgets(buffer, BUFFERSIZE, stdin);
    size_t expression_len = strlen(buffer); 
    if (validate_braces(buffer, expression_len) == 1)
        printf("Paranthesis are balanced\n");
    else
        printf("Paranthesis are not balanced\n");
    return 0;
}