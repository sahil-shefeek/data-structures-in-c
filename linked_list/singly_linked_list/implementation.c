#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

Node *head;

void insertHead(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->link = head;
    head = temp;
    printf("Inserted %d succesfully!\n", x);
}

void insertEnd(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->link = NULL;
    Node *ptr = head;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = temp;
    printf("Inserted %d succesfully!\n", x);
}

void insertAt(int x, int n)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    if (n == 1)
    {
        temp->link = head;
        head = temp;
    }
    else
    {
        Node *ptr = head;
        for (int i = 0; i < n - 2; i++)
        {
            if (ptr->link == NULL)
            {
                printf("Position %d is out of order!\n"
                       "Inserting at the end instead.\n",
                       n);
                insertEnd(x);
                printf("Inserted %d succesfully!\n", x);
                free(temp);
                return;
            }
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
    printf("Inserted %d at postion %d succesfully!\n", x, n);
}

void deleteHead()
{
    if (head == NULL)
        printf("Deletion not possible\n");
    else
    {
        Node *temp = head;
        head = temp->link;
        printf("Deleted %d\n\n", temp->data);
        free(temp);
    }
}
void deleteEnd()
{

    if (head == NULL)
        printf("Deletion not possible\n");
    else
    {
        Node *ptr = head;
        if (ptr->link == NULL)
        {
            head = NULL;
            printf("Deleted %d\n\n", ptr->data);
            free(ptr);
        }
        else
        {
            while (ptr->link->link != NULL)
                ptr = ptr->link;
            Node *temp = ptr->link;
            ptr->link = NULL;
            printf("Deleted %d\n\n", temp->data);
            free(temp);
        }
    }
}
void deleteAt(int n)
{
    if (head == NULL)
        printf("Deletion not possible\n");
    else
    {
        int pos, i = 0;
        printf("Enter the position to delete:\n");
        scanf("%d", &pos);
        Node *ptr = head;
        while (i < n - 2)
        {
            if (ptr->link == NULL)
                printf("Deletion not possible, Invalid position!\n\n");
            else
            {
                i++;
                ptr = ptr->link;
            }
        }
        Node *temp = ptr->link;
        ptr->link = temp->link;
        printf("Deleted %d\n\n", temp->data);
        free(temp);
    }
}

void print()
{
    if (head == NULL)
        printf("List is empty!\n");
    else
    {
        Node *temp = head;
        printf("List elements are :\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    head = NULL;
    int option, item, n;
    while (1)
    {
        printf("Select operation\n"
               "1. Insert at HEAD\n2. Insert at N\n"
               "3. Insert at END\n4. Delete at HEAD\n"
               "5. Delete at N\n6. Delete at END\n"
               "7. Print list\n8. Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the item to be inserted: \n");
            scanf("%d", &item);
            insertHead(item);
            break;

        case 2:
            printf("Enter the item to be inserted: \n");
            scanf("%d", &item);
            printf("Enter the position to insert %d: \n", item);
            scanf("%d", &n);
            insertAt(item, n);
            break;

        case 3:
            printf("Enter the item to be inserted: \n");
            scanf("%d", &item);
            insertEnd(item);
            break;

        case 4:
            deleteHead();
            break;

        case 5:
            printf("Enter the position to delete: \n");
            scanf("%d", &n);
            deleteAt(n);
            break;

        case 6:
            deleteEnd();
            break;

        case 7:
            print();
            break;

        case 8:
            return 0;

        default:
            printf("Invalid operation!\n");
        }
    }
}