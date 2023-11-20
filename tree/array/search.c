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
    int key, root_value, height;
    printf("Enter the height of the tree: ");
    scanf("%d", &height);
    MAX_SIZE = pow(2, height + 1);
    int arr[MAX_SIZE];
    memset(arr, -1, MAX_SIZE * sizeof(int));
    printf("Enter the root value: ");
    scanf("%d", &root_value);
    build_tree(arr, 1, root_value);
    print_tree(arr, MAX_SIZE);
    printf("Enter the value to be searched: ");
    scanf("%d", &key);
    int index = search(arr, 1, key);
    if (index == 0)
        printf("Element not found!\n");
    else
        printf("Element found at index: %d\n", index);
    return 0;
}
