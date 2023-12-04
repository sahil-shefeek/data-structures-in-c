#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex
{
    char data;
    struct Vertex *link;
} Vertex;

typedef struct Node
{
    char data;
    struct Node *link;
} Node;

Node *front = NULL, *rear = NULL, *top = NULL;

char visited[20];

void push(char item)
{
    Node *ptr, *new1 = (Node *)malloc(sizeof(Node));
    new1->data = item;
    new1->link = NULL;
    new1->link = top;
    top = new1;
}

char pop()
{
    char del;
    Node *temp = top;
    del = temp->data;
    top = top->link;
    free(temp);
    return del;
}

void enqueue(char item)
{
    Node *new1 = (Node *)malloc(sizeof(Node));
    new1->data = item;
    new1->link = NULL;
    if (front == NULL)
        front = new1;
    else
        rear->link = new1;
    rear = new1;
}

char dequeue()
{
    char del;
    Node *temp = front;
    del = temp->data;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->link;
    free(temp);
    return del;
}

int search(char key, char *visit, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (visit[i] == key)
            return 1;
    }
    return -1;
}

int insert(char ch, int i)
{
    visited[i] = ch;
    return 1;
}

void readedges(Vertex *p, int n)
{
    int i;
    Vertex *adj;
    printf("Enter the adjacent vertices :\n");
    for (i = 0; i < n; i++)
    {
        adj = (Vertex *)malloc(sizeof(Vertex));
        scanf(" %c", &adj->data);
        adj->link = NULL;
        p->link = adj;
        p = adj;
    }
}

void print(Vertex **arr, int size)
{
    Vertex *p;
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d : %c :", i + 1, arr[i]->data);
        for (p = arr[i]->link; p != NULL; p = p->link)
            printf(" %c", p->data);
        printf("\n");
    }
}

int indexof(Vertex **arr, int size, char ch)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i]->data == ch)
            return i;
    }
    return -1;
}

void bfs(Vertex *a[], int n)
{
    int i = 0;
    Vertex *p;
    char u = a[0]->data;
    enqueue(u);
    while (front != NULL)
    {
        u = dequeue();
        if (search(u, visited, n) == -1)
        {
            i += insert(u, i);
            if (indexof(a, n, u) != -1)
            {
                for (p = a[indexof(a, n, u)]; p != NULL; p = p->link)
                    enqueue(p->data);
            }
        }
    }
    printf("Visited: ");
    for (n = 0; n < i; n++)
        printf(" %c", visited[n]);
    printf("\n");
}

void dfs(Vertex *a[], int n)
{
    int i = 0;
    Vertex *p;
    char u = a[0]->data;
    push(u);
    while (top != NULL)
    {
        u = pop();
        if (search(u, visited, n) == -1)
        {
            i += insert(u, i);
            if (indexof(a, n, u) != -1)
            {
                for (p = a[indexof(a, n, u)]; p != NULL; p = p->link)
                    push(p->data);
            }
        }
    }
    printf("DFS Visited :");
    for (n = 0; n < i; n++)
        printf(" %c", visited[n]);
    printf("\n");
}

int main()
{
    int n, i, k;
    Vertex *adj[20];
    printf("Enter the number of vertices :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        adj[i] = (Vertex *)malloc(sizeof(Vertex));
        printf("Enter Vertex %d:", i + 1);
        scanf(" %c", &adj[i]->data);
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter number of adjacent vertices of Vertex %d:", i + 1);
        scanf("%d", &k);
        readedges(adj[i], k);
    }
    print(adj, n);
    bfs(adj, n);
    dfs(adj, n);
    return 0;
}