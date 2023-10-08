#include <stdio.h>
#define MAX_SIZE 5

typedef struct
{
    int queue[MAX_SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q1, int item)
{
    if (q1->front == (q1->rear + 1) % MAX_SIZE)
        printf("Queue is full!\n");
    else
    {
        if (q1->front == -1)
            q1->front = 0;
        q1->rear = q1->rear + 1;
        q1->queue[q1->rear] = item;
    }
}

void dequeue(Queue *q1)
{
    if (q1->front == -1)
        printf("Queue is empty!\n");
    else
    {
        int del = q1->queue[q1->front];
        q1->front++;
        if (q1->front > q1->rear)
        {
            q1->front = -1;
            q1->rear = -1;
        }
        printf("Deleted %d\n", del);
    }
}

void list(Queue *q1)
{
    if (q1->front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are :\n");
    for (int i = q1->front; i <= q1->rear && q1->front != -1; i++)
        printf("%d \t", q1->queue[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    Queue q1;
    q1.front = -1;
    q1.rear = -1;

    int choice, item;
    while (1)
    {
    get_choice:
        printf("Select operation:\n1. Enqueue\n2. Dequeue\n3. List\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to add:\n");
            scanf("%d", &item);
            enqueue(&q1, item);
            break;

        case 2:
            dequeue(&q1);
            break;

        case 3:
            list(&q1);
            break;

        case 4:
            return 0;

        default:
            printf("Invalid operation!\nTry again.\n");
            goto get_choice;
        }
    }
    return 0;
}