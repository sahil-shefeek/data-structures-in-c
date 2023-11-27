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
               "1. In-Order\n2. Pre-Order\n"
               "3. Post-Order\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Inorder representation of tree: ");
            in_order(root);
            printf("\n");
            break;

        case 2:
            printf("Preorder representation of tree: ");
            pre_order(root);
            printf("\n");
            break;

        case 3:
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
