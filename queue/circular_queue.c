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
        printf("Queue is full!\n\n");
    else
    {
        if (q1->front == -1)
            q1->front = 0;
        q1->rear = (q1->rear + 1) % MAX_SIZE;
        q1->queue[q1->rear] = item;
        printf("Added %d\n", item);
    }
}

void dequeue(Queue *q1)
{
    if (q1->front == -1)
        printf("Queue is empty!\n\n");
    else
    {
        int del = q1->queue[q1->front];

        if (q1->front == q1->rear)
        {
            q1->front = -1;
            q1->rear = -1;
        }
        else
            q1->front = (q1->front + 1) % MAX_SIZE;
        printf("Deleted %d\n", del);
    }
}

void list(Queue *q1)
{
    if (q1->front == -1)
    {
        printf("Queue is empty!\n\n");
        return;
    }
    printf("Front ==> %d\n", q1->front);
    printf("Queue elements are :\n");
    int i = q1->front;
    do
    {
        printf("%d \t", q1->queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (q1->rear + 1) % MAX_SIZE);
    printf("\n");
    printf("Rear ==>  %d\n\n", q1->rear);
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
        printf("Select operation:\n"
               "1. Enqueue\n2. Dequeue\n"
               "3. List\n4. Exit\n");
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