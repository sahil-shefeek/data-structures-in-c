#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next, *prev;
} Node;

Node *head, *tail;

void insertHead(int x)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = x;
	new->prev = NULL;
	if (head != NULL)
		new->next = head;
	else
	{
		new->next = NULL;
		tail = new;
	}
	head = new;
	printf("Inserted %d successfully!\n", x);
}

void insertAt(int x, int pos)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = x;
	if (pos == 1)
	{
		new->prev = NULL;
		if (head != NULL)
			new->next = head;
		else
		{
			new->next = NULL;
			tail = new;
		}
		head = new;
	}
	else
	{
		Node *ptr = head;
		for (int i = 0; i < pos - 2; i++)
		{
			if (ptr->next == NULL)
				break;
			else
				ptr = ptr->next;
		}
		new->prev = ptr;
		new->next = ptr->next;
		if (ptr->next != NULL)
			ptr->next->prev = new;
		ptr->next = new;
		if (ptr == tail)
			tail = new;
		printf("Inserted %d successfully!\n", x);
	}
}

void insertEnd(int x)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = x;
	new->next = NULL;
	new->prev = tail;
	if (head == NULL)
		head = new;
	else
		tail->next = new;
	tail = new;
	printf("Inserted %d successfully!\n", x);
}

void deleteHead()
{
	if (head == NULL)
		printf("List is empty!");
	else
	{
		Node *temp = head;
		if (head == tail)
		{
			tail = NULL;
			head = NULL;
		}
		else
			head = head->next;
		printf("Deleted %d\n", temp->data);
		free(temp);
	}
}

void deleteAt(int pos)
{
	if (head == NULL)
		printf("Linked list is empty!\n");
	else
	{
		Node *temp = head;
		if (pos == 1)
		{
			if (head == tail)
			{
				tail = NULL;
				head = NULL;
			}
			else
				head = head->next;
		}
		else
		{
			if (head == tail)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				Node *ptr = head;
				for (int i = 1; i < pos - 1; i++)
					ptr = ptr->next;
				Node *temp = ptr->next;
				ptr->next = temp->next;
				if (temp->next == NULL)
					tail = ptr;
				else
					temp->next->prev = temp->prev;
			}
		}
		printf("Deleted %d successfully!\n", temp->data);
		free(temp);
	}
}

void deleteEnd()
{
	if (head == NULL)
		printf("List is empty!");
	else
	{
		Node *temp = tail;
		if (head == tail)
		{
			tail = NULL;
			head = NULL;
		}
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		printf("Deleted %d\n", temp->data);
		free(temp);
	}
}

void print()
{
	if (head == NULL)
		printf("List is empty!\n");
	else
	{
		printf("List elements are:\n");
		Node *ptr = head;
		while (ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
		printf("\n\n");
	}
}

void printRev()
{
	if (head == NULL)
		printf("List is empty!\n");
	else
	{
		printf("List elements are:\n");
		Node *ptr = tail;
		while (ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->prev;
		}
		printf("\n\n");
	}
}

int main()
{

	head = NULL;
	tail = NULL;

	int choice, x, pos;
	while (1)
	{
		printf("Select operation:\n"
			   "1. Insertion at Beginning\n"
			   "2. Insertion at N\n"
			   "3. Insertion at End\n"
			   "4. Deletion at Beginning\n"
			   "5. Deletion at N\n"
			   "6. Deletion at End\n"
			   "7. Print list\n"
			   //"8. Print list in reverse\n"
			   "9. Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the element to be inserted: \n");
			scanf("%d", &x);
			insertHead(x);
			break;

		case 2:
			printf("Enter the position to insert into: \n");
			scanf("%d", &pos);
			printf("Enter the element to be inserted: \n");
			scanf("%d", &x);
			insertAt(x, pos);
			break;

		case 3:
			printf("Enter the element to be inserted: \n");
			scanf("%d", &x);
			insertEnd(x);
			break;

		case 4:
			deleteHead();
			break;

		case 5:
			printf("Enter the position to delete from: \n");
			scanf("%d", &pos);
			deleteAt(pos);
			break;

		case 6:
			deleteEnd();
			break;

		case 7:
			print();
			break;

		case 8:
			printRev();
			break;

		case 9:
			return 0;

		default:
			printf("Invalid choice!\n"
				   "Try again.\n");
		}
	}
}
