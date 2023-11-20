#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

Node *new, *temp, *head, *ptr1, *ptr;
int pos;

void insertHead()
{
    new = (Node *)malloc(sizeof(Node));
    printf("Enter element to be inserted\n");
    scanf("%d", &new->data);
    new->link = NULL;
    if (head == NULL)
    {
        head = new;
        head->link = head;
    }
    else
    {
        ptr = head;
        while (ptr->link != head)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
        new->link = head;
        head = new;
    }
    printf("Inserted %d successfully!\n", new->data);
}

void insertEnd()
{
    new = (Node *)malloc(sizeof(Node));
    printf("Enter element to be inserted\n");
    scanf("%d", &new->data);
    new->link = NULL;
    if (head == NULL)
    {
        head = new;
        head->link = head;
    }
    else
    {
        ptr = head;
        while (ptr->link != head)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
        new->link = head;
    }
    printf("Inserted %d successfully!\n", new->data);
}

void insertAt()
{
    printf("Enter the position to insert into\n");
    scanf("%d", &pos);
    if (pos == 1)
        insertHead();
    else
    {
        new = (Node *)malloc(sizeof(Node));
        printf("Enter element to be inserted\n");
        scanf("%d", &new->data);
        new->link = NULL;
        ptr = head;
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->link;
        }
        new->link = ptr->link;
        ptr->link = new;
    }
    printf("Inserted %d successfully!\n", new->data);
}

void deleteHead()
{
    if (head == NULL)
        printf("List is empty!\n");
    else
    {
        if (head->link == head)
        {
            temp = head;
            head = NULL;
        }
        else
        {
            temp = head;
            ptr = head;
            while (ptr->link != head)
                ptr = ptr->link;
            ptr->link = head->link;
            head = head->link;
        }
        printf("Deleted %d successfully!\n", temp->data);
        free(temp);
    }
}

void deleteEnd()
{
    if (head == NULL)
        printf("List is empty!\n");
    else
    {
        if (head->link == head)
        {
            temp = head;
            head = NULL;
        }
        else
        {
            ptr = head;
            while (ptr->link != head)
            {
                ptr1 = ptr;
                ptr = ptr->link;
            }
            temp = ptr;
            ptr1->link = head;
        }
        printf("Deleted %d successfully!\n", temp->data);
        free(temp);
    }
}

void deleteAt()
{
    if (head == NULL)
        printf("List is empty!\n");
    else
    {
        printf("Enter the position to delete from:\n");
        scanf("%d", &pos);
        if (pos == 1)
        {
            deleteHead();
        }
        else
        {
            ptr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                ptr = ptr->link;
            }
            temp = ptr->link;
            ptr->link = temp->link;
            printf("Deleted %d successfully!\n", temp->data);
            free(temp);
        }
    }
}

void print()
{
    if (head == NULL)
        printf("List is empty!\n");
    else
    {
        printf("List items are:\t");
        ptr = head;
        while (ptr->link != head)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("%d\n\n", ptr->data);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Insertion at HEAD\n2. Insertion at END\n"
               "3. Insertion at N\n4. Deletion from HEAD\n"
               "5. Deletion from END\n6. Deletion from N\n"
               "7. Print list\n8. Exit\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertHead();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            insertAt();
            break;

        case 4:
            deleteHead();
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            deleteAt();
            break;

        case 7:
            print();
            break;

        case 8:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
