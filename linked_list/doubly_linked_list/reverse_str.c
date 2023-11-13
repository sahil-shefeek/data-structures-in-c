#include <stdio.h>
#include <string.h>

#define SIZE 100

typedef struct Node
{
    char data;
    struct Node *next, *prev;

} Node;

Node *head = NULL, *tail = NULL;

int main(int argc, char *argv[])
{

    char str[SIZE + 1], rev[SIZE + 1];
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        insertEnd(i);
    int i = 0;
    Node *ptr = tail;
    while (ptr != NULL)
    {
        rev[i++] = ptr->data;
        ptr = ptr->next;
    }
    printf("%s\n", rev);
    return 0;
}
