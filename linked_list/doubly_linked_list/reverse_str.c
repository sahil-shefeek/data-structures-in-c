#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

typedef struct Node
{
    char data;
    struct Node *next, *prev;

} Node;

Node *head = NULL, *tail = NULL;

void insertEnd(char ch)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = ch;
    new->prev = NULL;
    new->next = NULL;
    if (head == NULL)
        head = new;
    else
    {
        tail->next = new;
        new->prev = tail;
    }
    tail = new;
}

int main(int argc, char *argv[])
{
    char str[SIZE + 1], rev[SIZE + 1];
    printf("Enter a string:\n");
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        insertEnd(str[i]);
    int i = 0;
    Node *ptr = tail;
    while (ptr != NULL)
    {
        rev[i++] = ptr->data;
        ptr = ptr->prev;
    }
    rev[i] = '\0';
    printf("%s\n", rev);
    return 0;
}
