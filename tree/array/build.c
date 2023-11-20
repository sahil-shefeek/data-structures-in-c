#include <stdio.h>
#include <string.h>
#include <math.h>

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

void print_tree(int *arr, size_t size)
{
    for (int i = 0; i <= size + 1; i++)
    {
        if (arr[i] != -1)
            printf("%d\t", arr[i]);
        else
            printf("___\t");
    }
    printf("\n");
}

int main()
{
    int root_value, height;
    printf("Enter the height of the tree: ");
    scanf("%d", &height);
    MAX_SIZE = pow(2, height + 1) - 1;
    int arr[MAX_SIZE];
    memset(arr, -1, MAX_SIZE * sizeof(int));
    printf("Enter the root value: ");
    scanf("%d", &root_value);
    build_tree(arr, 1, root_value);
    print_tree(arr, MAX_SIZE);
    return 0;
}