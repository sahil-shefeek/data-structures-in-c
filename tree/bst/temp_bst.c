#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *root, *parent;

Node *search(int value)
{
    Node *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == value)
            return ptr;
        else
        {
            parent = ptr;
            if (ptr->data > value)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    return ptr;
}

void insert(int value)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = value;
    new->right = new->left = NULL;
    if (root == NULL)
        root = new;
    else
    {
        Node *ptr = root;
        while (ptr != NULL)
        {
            parent = ptr;
            if (ptr->data > value)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (parent->data > value)
            parent->left = new;
        else
            parent->right = new;
    }
}

Node *getInorderSuccessor(Node *ptr)
{
    ptr = ptr->right;
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

void delete(int value)
{
    Node *inorderSuccessor, *temp;
    Node *ptr = search(value);
    if (ptr == NULL)
        printf("Element not found deletion not possible \n");
    else if (ptr->left != NULL && ptr->right != NULL)
    {
        inorderSuccessor = getInorderSuccessor(ptr);
        delete (inorderSuccessor->data);
        ptr->data = inorderSuccessor->data;
    }
    else
    {
        if (ptr->left == NULL && ptr->right == NULL)
            temp = NULL;
        else if (ptr->right == NULL)
            temp = ptr->left;
        else if (ptr->left == NULL)
            temp = ptr->right;

        if (ptr == root)
            root = temp;
        else if (parent->left == ptr)
            parent->left = temp;
        else
            parent->right = temp;
    }
}

void preorder(Node *ptr)
{
    if (ptr != NULL)
    {
        printf(" %d", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(Node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf(" %d", ptr->data);
    }
}

void inorder(Node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf(" %d", ptr->data);
        inorder(ptr->right);
    }
}

void display()
{
    if (root == NULL)
        printf("Tree is empty\n");
    else
    {
        printf("Preorder representation of tree : ");
        preorder(root);
        printf("\n");
        printf("Inorder representation of tree : ");
        inorder(root);
        printf("\n");
        printf("Postorder representation of tree : ");
        postorder(root);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("Select Operation:\n"
               "1. Insert\n2. Delete\n"
               "3. Search\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("Enter the value of Node to delete: ");
            scanf("%d", &value);
            delete (value);
            break;
        case 3:
            printf("Enter the value of Node to search: ");
            scanf("%d", &value);
            if (search(value) != NULL)
                printf("%d is found!\n", value);
            else
                printf("%d is not found!\n", value);
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid input!\n");
        }
    }

    return 0;
}
