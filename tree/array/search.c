#include <stdio.h>
size_t MAX_SIZE;

void build_tree(int *arr, int index, int value)
{
    int e;
    char c;
    arr[index] = value;
    if (2 * index < MAX_SIZE)
    {
        printf("Do you want Left child for %d ? (Y/N) : ", index);
        scanf(" %c", &c);
        if (c == 'y' || c == 'Y')
        {
            printf("Enter the element :");
            scanf("%d", &e);
            build_tree(arr, 2 * index, e);
        }
        printf("Do you want Right child for %d ? (Y/N) : ", index);
        scanf(" %c", &c);
        if (c == 'y' || c == 'Y')
        {
            printf("Enter the element :");
            scanf("%d", &e);
            build_tree(arr, 2 * index + 1, e);
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

int main()
{
    int key, root_value, height;
    printf("Enter the height of the tree: ");
    scanf("%d", &height);
    MAX_SIZE = pow(2, height + 1) - 1;
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