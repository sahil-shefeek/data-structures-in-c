#include <stdio.h>
#define MAX_SIZE 5

typedef struct
{
    int queue[MAX_SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q1, int element)
{
    if (q1->rear == MAX_SIZE - 1)
    {
        printf("Queue is full!\n\n");
        return;
    }
    else
    {
        if (q1->front == -1)
            q1->front = 0;
        q1->rear++;
        q1->queue[q1->rear] = element;
    }
}

void dequeue(Queue *q1)
{
    if (q1->front == -1)
    {
        printf("Queue is empty!\n\n");
        return;
    }
    else
    {
        int del = q1->queue[q1->front];
        if (q1->front == q1->rear)
        {
            q1->front = -1;
            q1->rear = -1;
        }
        else
            q1->front++;
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
    printf("Queue elements are :\n");
    for (int i = q1->front; i <= q1->rear; i++)
        printf("%d \t", q1->queue[i]);
    printf("\n\n");
}

int main(int argc, char *argv[])
{
    Queue q1;
    q1.front = -1;
    q1.rear = -1;

    int choice, element;
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
            printf("Enter element to add:\n");
            scanf("%d", &element);
            enqueue(&q1, element);
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
            printf("Invalid operation!\nTry again.\n\n");
            goto get_choice;
        }
    }
    return 0;
}