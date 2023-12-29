#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex
{
    int data;
    struct Vertex *link;
} Vertex;

typedef struct Node
{
    int data;
    struct Node *link;
} Node;
Node *front = NULL, *rear = NULL, *top = NULL;

void push(int item)
{
    Node *ptr, *new = (Node *)malloc(sizeof(Node));
    new->data = item;
    new->link = NULL;
    new->link = top;
    top = new;
}

int pop()
{
    int del;
    Node *temp = top;
    del = temp->data;
    top = top->link;
    free(temp);
    return del;
}

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

int dequeue()
{
    Node *temp = front;
    int del = temp->data;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->link;
    free(temp);
    return del;
}

int search(int key, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return 1;
    }
    return -1;
}

void readedges(Vertex *p, int n)
{

    printf("Enter the adjacent vertices:\n");
    for (int i = 0; i < n; i++)
    {
        Vertex *adj = (Vertex *)malloc(sizeof(Vertex));
        scanf(" %d", &adj->data);
        adj->link = NULL;
        p = p->link = adj;
    }
}

void print(Vertex **arr, int n)
{
    Vertex *p;
    for (int i = 0; i < n; i++)
    {
        printf("%d :", arr[i]->data);
        for (p = arr[i]->link; p != NULL; p = p->link)
            printf(" %d", p->data);
        printf("\n");
    }
}

int indexof(Vertex **arr, int n, int d)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i]->data == d)
            return i;
    }
    return -1;
}

void bfs(Vertex **arr, int n)
{
    int i, visited[20];
    Vertex *p;
    int u;
    printf("Enter the start Node: ");
    scanf("%d", &u);
    for (i = n; i > 0; i--)
        visited[i] = 0;
    enqueue(u);
    while (front != NULL)
    {
        u = dequeue();
        if (search(u, visited, n) == -1)
        {
            visited[i++] = u;
            if (indexof(arr, n, u) != -1)
            {
                for (p = arr[indexof(arr, n, u)]; p != NULL; p = p->link)
                    enqueue(p->data);
            }
        }
    }
    printf("BFS Visited: ");
    for (n = 0; n < i; n++)
        printf(" %d", visited[n]);
    printf("\n");
}

void dfs(Vertex **arr, int n)
{
    int i, dfsvisited[20];
    Vertex *p;
    int u;
    printf("Enter the start Node: ");
    scanf("%d", &u);
    for (i = n; i > 0; i--)
        dfsvisited[i] = 0;
    push(u);
    while (top != NULL)
    {
        u = pop();
        if (search(u, dfsvisited, n) == -1)
        {
            dfsvisited[i++] = u;
            if (indexof(arr, n, u) != -1)
            {
                for (p = arr[indexof(arr, n, u)]; p != NULL; p = p->link)
                    push(p->data);
            }
        }
    }
    printf("DFS Visited: ");
    for (n = 0; n < i; n++)
        printf(" %d", dfsvisited[n]);
    printf("\n");
}

int main()
{
    int n, i, k, choice;
    Vertex *arr[20];
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        arr[i] = (Vertex *)malloc(sizeof(Vertex));
        printf("Enter Vertex %d: ", i + 1);
        scanf(" %d", &arr[i]->data);
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter number of adjacent vertices of Vertex %d: ", i + 1);
        scanf("%d", &k);
        readedges(arr[i], k);
    }
    printf("Adjacency list: \n");
    print(arr, n);
    while (1)
    {
        printf("Select operation:\n"
               "1. BFS\n2. DFS\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bfs(arr, n);
            break;
        case 2:
            dfs(arr, n);
        case 3:
            return 0;
        default:
            printf("Invalid input!\n");
        }
    }
    return 0;
}