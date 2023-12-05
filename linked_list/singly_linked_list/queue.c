#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *link;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int item)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = item;
	new->link = NULL;
	if (front == NULL)
		front = new;
	else
		rear->link = new;
	rear = new;
}

void dequeue()
{
	if (front == NULL)
		printf("Queue is empty!\n");
	else
	{
		Node *temp = front;
		printf("Deleted: %d\n", temp->data);
		if (front->link == NULL)
			rear = NULL;
		front = front->link;
		free(temp);
	}
}

void print()
{
	if (front == NULL)
		printf("Queue is empty!\n");
	else
	{
		printf("Queue elements are:\n");
		Node *ptr = front;
		while (ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->link;
		}
		printf("\n");
	}
}

int main()
{
	int item, choice;
	while (1)
	{
		printf("\n***Menu***\n"
			   "1. Enqueue\n2. Dequeue\n"
			   "3. Print queue items\n4. Exit\n"
			   "\nEnter the choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element to be inserted:\n");
			scanf("%d", &item);
			enqueue(item);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			print();
			break;

		case 4:
			return 0;

		default:
			printf("Invalid choice\n");
		}
	}
}
