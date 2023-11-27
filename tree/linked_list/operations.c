#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;

} Node;

void build_tree(Node *ptr, int value)
{
	ptr->data = value;
	ptr->left = NULL;
	ptr->right = NULL;
	int item;
	char choice;
	printf("Do you want to left child for Node %d(Y/N):", value);
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y')
	{
		printf("Enter the value to insert: ");
		scanf("%d", &item);
		ptr->left = (Node *)malloc(sizeof(Node));
		build_tree(ptr->left, item);
	}
	printf("Do you want to right child for Node %d(Y/N):", value);
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y')
	{
		printf("Enter the value to insert: ");
		scanf("%d", &item);
		ptr->right = (Node *)malloc(sizeof(Node));
		build_tree(ptr->right, item);
	}
}

void pre_order(Node *ptr)
{
	if (ptr != NULL)
	{
		printf("%d\t", ptr->data);
		pre_order(ptr->left);
		pre_order(ptr->right);
	}
}
void post_order(Node *ptr)
{
	if (ptr != NULL)
	{
		post_order(ptr->left);
		post_order(ptr->right);
		printf("%d\t", ptr->data);
	}
}

void in_order(Node *ptr)
{
	if (ptr != NULL)
	{
		in_order(ptr->left);
		printf("%d\t", ptr->data);
		in_order(ptr->right);
	}
}

Node *search(Node *ptr, int key)
{

	if (ptr->data == key)
		return ptr;
	else
	{
		Node *x = NULL;
		if (ptr->left != NULL)
			x = search(ptr->left, key);
		if (ptr->right != NULL && x == NULL)
			x = search(ptr->right, key);
		return x;
	}
}

void delete(Node *ptr, int key)
{
	ptr = search(ptr, key);
	if (ptr == NULL)
		printf("Deletion not possible: %d was not found!\n", key);
	else
	{
		if (ptr->left == NULL && ptr->right == NULL)
			ptr = NULL;
		else
			printf("Deletion not possible!\n");
	}
}

void insert(struct Node *ptr, int key)
{
	char choice;
	ptr = search(ptr, key);
	if (ptr == NULL)
		printf("Insertion not possible: Element %d was not found!\n", key);
	else
	{
		int value;
		printf("Create a right child or left child for Node %d (R/L):", key);
		scanf(" %c", &choice);
		if (choice == 'l' || choice == 'L')
		{
			if (ptr->left == NULL)
			{
				printf("Enter the value to insert: ");
				scanf("%d", &value);
				ptr->left = (Node *)malloc(sizeof(Node));
				ptr->left->left = NULL;
				ptr->left->right = NULL;
				ptr->left->data = value;
			}
			else
				printf("Insertion not possible!\n");
		}
		else if (choice == 'r' || choice == 'R')
		{
			if (ptr->right == NULL)
			{
				printf("Enter the value to insert: ");
				scanf("%d", &value);
				ptr->left = (Node *)malloc(sizeof(Node));
				ptr->left->left = NULL;
				ptr->left->right = NULL;
				ptr->left->data = value;
			}
			else
				printf("Insertion not possible!\n");
		}
		else
			printf("Invalid choice!\n");
	}
}

int main()
{
	int value, choice;
	Node *root = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter the value of root node: ");
	scanf("%d", &value);
	build_tree(root, value);
	while (1)
	{
		printf("Select operation:\n"
			   "1. Insertion\n2. Deletion\n"
			   "3. Display Tree\n4. Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the value of Node to search for inserting: ");
			scanf("%d", &value);
			insert(root, value);
			break;

		case 2:
			printf("Enter the value of Node to delete: ");
			scanf("%d", &value);
			delete (root, value);
			break;

		case 3:
			printf("Preorder representation of tree: ");
			pre_order(root);
			printf("\n");
			printf("Inorder representation of tree: ");
			in_order(root);
			printf("\n");
			printf("Postorder representation of tree: ");
			post_order(root);
			printf("\n");
			break;

		case 4:
			return 0;

		default:
			printf("Invalid choice!\n");
			break;
		}
	}
}
