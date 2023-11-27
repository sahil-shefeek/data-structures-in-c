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
	printf("\n");
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

int main()
{
	int value, choice, key;
	Node *root = (Node *)malloc(sizeof(Node));
	printf("Enter the value of root node: ");
	scanf("%d", &value);
	build_tree(root, value);
	printf("Preorder representation of tree:\n");
	pre_order(root);
	printf("Enter the value of Node to search for: ");
	scanf("%d", &key);
	Node *ptr = search(ptr, key);
	if (ptr == NULL)
		printf("Element %d was not found!\n", key);
	else
		printf("Element %d was found!\n", key);
	return 0;
}
