#include <stdio.h>
#define MAX_SIZE 5

int q[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int item)
{
    if (rear == MAX_SIZE - 1)
        printf("Queue Overflow!\n");
    else
    {
        if (front == -1)
            front = 0;
        q[++rear] = item;
    }
}

void dequeue()
{
    int element;
    if (front == -1)
        printf("Queue Underflow!\n");
    else
    {
        element = q[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = front + 1;
        printf("Deleted %d\n", element);
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty!\n");
    else
    {
        printf("Queue elements are :");
        for (i = front; i < rear; i++)
            printf("%d ", q[i]);
        printf("%d \n", q[i]);
    }
}

int main()
{
    int choice, element;
    while (1)
    {
        printf("Select operation:\n"
               "1. Enqueue\n2. Dequeue\n"
               "3. List\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to add:\n");
            scanf("%d", &element);
            enqueue(element);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid operation!\nTry again.\n\n");
        }
    }
    return 0;
}