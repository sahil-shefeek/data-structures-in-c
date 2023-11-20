#include <stdio.h>
#include <string.h>
#include <math.h>

size_t MAX_SIZE;

void build_tree(int *arr, int index, int value)
{
	int new_value;
	char choice;
	arr[index] = value;
	if (2 * index < MAX_SIZE)
	{
		printf("Do you want Left child for %d ? (Y/N): ", index);
		scanf(" %c", &choice);
		if (choice == 'y' || choice == 'Y')
		{
			printf("Enter the value to insert: ");
			scanf("%d", &new_value);
			build_tree(arr, 2 * index, new_value);
		}
		printf("Do you want Right child for %d ? (Y/N): ", index);
		scanf(" %c", &choice);
		if (choice == 'y' || choice == 'Y')
		{
			printf("Enter the value to insert: ");
			scanf("%d", &new_value);
			build_tree(arr, 2 * index + 1, new_value);
		}
	}
}

int search(int *arr, int index, int key)
{
	if (arr[index] == -1)
		return 0;
	if (arr[index] == key)
		return index;
	else
	{
		int x;
		if (2 * index <= MAX_SIZE)
			x = search(arr, 2 * index, key);
		else
			return 0;
		if (x == 0)
		{
			if (2 * index + 1 <= MAX_SIZE)
				x = search(arr, 2 * index + 1, key);
			return x;
		}
	}
}

void insertAt(int *arr, int key)
{
	int index = search(arr, 1, key);
	if (index == 0)
		printf("Insertion not possible!\n");
	else
	{
		char choice;
		int value;
		printf("Do you want Left child or Right child for %d ? (L/R): ", key);
		scanf(" %c", &choice);
		if (choice == 'l' || choice == 'L')
		{
			if (arr[2 * index] == -1)
			{
				printf("Enter the value to insert: ");
				scanf("%d", &value);
				arr[2 * index] = value;
				printf("Inserted %d successfully!\n", value);
			}
			else
				printf("Insertion not possible!\n");
		}
		else
		{
			if (arr[2 * index + 1] == -1)
			{
				printf("Enter the value to insert: ");
				scanf("%d", &value);
				arr[2 * index + 1] = value;
				printf("Inserted %d successfully!\n", value);
			}
			else
				printf("Insertion not possible!\n");
		}
	}
}

void delete_node(int *arr, int key)
{
	int index = search(arr, 1, key);
	if (index == 0)
		printf("Deletion not possible!\n");
	else
	{
		if (2 * index > MAX_SIZE)
			arr[index] = -1;
		else
		{
			if (arr[2 * index] == -1 && arr[2 * index + 1] == -1)
				arr[index] = -1;
			else
			{
				printf("Deletion not possible!\n");
				return;
			}
		}
		printf("Deleted %d successfully!\n", key);
	}
}

void print_tree(int *arr, size_t size)
{
	printf("\nArray representation of the tree is:\n");
	for (int i = 1; i < size; i++)
	{
		if (arr[i] != -1)
			printf("%d\t", arr[i]);
		else
			printf("__\t");
	}
	printf("\n");
}

int main()
{
	int key, root_value, height, choice;
	printf("Building tree...\n");
	printf("Enter the height of the tree: ");
	scanf("%d", &height);
	MAX_SIZE = pow(2, height + 1);
	int arr[MAX_SIZE];
	memset(arr, -1, MAX_SIZE * sizeof(int));
	printf("Enter the root value: ");
	scanf("%d", &root_value);
	build_tree(arr, 1, root_value);
	print_tree(arr, MAX_SIZE);
	while (1)
	{
		printf("Select operation:\n"
			   "1. Insertion\n2. Deletion\n"
			   "3. Print tree\n4. Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the node value to insert into: ");
			scanf("%d", &key);
			insertAt(arr, key);
			break;

		case 2:
			printf("Enter the node value to delete: ");
			scanf("%d", &key);
			delete_node(arr, key);
			break;

		case 3:
			print_tree(arr, MAX_SIZE);
			break;

		case 4:
			return 0;

		default:
			printf("Invalid option!\nTry again");
			break;
		}
	}
	return 0;
}
