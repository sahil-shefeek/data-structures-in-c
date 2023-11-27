#include <stdio.h>
#define MAX_SIZE 5

int q[MAX_SIZE];
int front = -1, rear = -1;

void enqueue_front(int item)
{
    if (front == (rear + 1) % MAX_SIZE)
        printf("Queue Overflow!\n");
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
            front = (front + MAX_SIZE - 1) % MAX_SIZE;
        q[front] = item;
    }
}

void enqueue_rear(int item)
{
    if (front == (rear + 1) % MAX_SIZE)
        printf("Queue Overflow!\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        q[rear] = item;
    }
}

void dequeue_front()
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
            front = (front + 1) % MAX_SIZE;
        printf("Deleted %d\n", element);
    }
}

void dequeue_rear()
{
    int element;
    if (front == -1)
        printf("Queue Underflow!\n");
    else
    {
        element = q[rear];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            rear = (rear + MAX_SIZE - 1) % MAX_SIZE;
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
        printf("Front ==>  %d\n", front);
        printf("Rear ==>  %d\n", rear);
        printf("Queue elements are :\n");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
            printf("%d ", q[i]);
        printf("%d\n", q[i]);
    }
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("Select operation:\n"
               "1. Enqueue via FRONT\n2. Dequeue via FRONT\n"
               "3. Enqueue via REAR\n4. Dequeue via REAR\n"
               "5. List\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to add:\n");
            scanf("%d", &item);
            enqueue_front(item);
            break;

        case 2:
            dequeue_front();
            break;
        case 3:
            printf("Enter item to add:\n");
            scanf("%d", &item);
            enqueue_rear(item);
            break;

        case 4:
            dequeue_rear();
            break;

        case 5:
            display();
            break;

        case 6:
            return 0;

        default:
            printf("Invalid operation!\nTry again.\n");
        }
    }
    return 0;
}