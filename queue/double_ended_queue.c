#include <stdio.h>
#define MAX_SIZE 5

typedef struct
{
    int queue[MAX_SIZE];
    int front;
    int rear;
} Queue;

void enqueue_front(Queue *q, int item)
{
    if (q->front == (q->rear + 1) % MAX_SIZE)
        printf("Queue is full!\n");
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
            q->rear = 0;
        }
        else
            q->front = (q->front + MAX_SIZE - 1) % MAX_SIZE;
        q->queue[q->front] = item;
        printf("Added %d\n", item);
    }
}

void enqueue_rear(Queue *q, int item)
{
    if (q->front == (q->rear + 1) % MAX_SIZE)
        printf("Queue is full!\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->queue[q->rear] = item;
    }
}

void dequeue_front(Queue *q)
{
    if (q->front == -1)
        printf("Queue is empty!\n");
    else
    {
        int del = q->queue[q->front];

        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->front = (q->front + 1) % MAX_SIZE;
        printf("Deleted %d\n", del);
    }
}

void dequeue_rear(Queue *q)
{
    if (q->front == -1)
        printf("Queue is empty!\n");
    else
    {
        int del = q->queue[q->rear];

        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->rear = (q->rear + MAX_SIZE - 1) % MAX_SIZE;
        printf("Deleted %d\n", del);
    }
}

void list(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front ==>  %d\n", q->front);
    printf("Queue elements are :\n");
    int i = q->front;
    while (1)
    {
        printf("%d \t", q->queue[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
    printf("Rear ==>  %d\n", q->rear);
}

int main(int argc, char *argv[])
{
    Queue q;
    q.front = -1;
    q.rear = -1;

    int choice, item;
    while (1)
    {
    get_choice:
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
            enqueue_front(&q, item);
            break;

        case 2:
            dequeue_front(&q);
            break;
        case 3:
            printf("Enter item to add:\n");
            scanf("%d", &item);
            enqueue_rear(&q, item);
            break;

        case 4:
            dequeue_rear(&q);
            break;

        case 5:
            list(&q);
            break;

        case 6:
            return 0;

        default:
            printf("Invalid operation!\nTry again.\n");
            goto get_choice;
        }
    }
    return 0;
}