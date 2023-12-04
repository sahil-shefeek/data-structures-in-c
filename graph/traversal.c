#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Node *front = NULL, *rear = NULL;

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
    int del = 0;
    if (front != NULL)
    {
        Node *temp = front;
        del = temp->data;
        // printf("Deleted: %d\n", del);
        if (front->link == NULL)
        {
            front = NULL;
            rear = NULL;
        }
        else
            front = front->link;
        free(temp);
    }
    return del;
}

void readGraph(Vertex **adj, int NUM_OF_VERTICES)
{
    for (int i = 0; i < NUM_OF_VERTICES; i++)
    {
        int num_of_adj;
        Vertex *ptr = NULL;
        printf("Enter the number of adjacent vertices for %d: ", i);
        scanf("%d", &num_of_adj);
        for (int j = 1; j <= num_of_adj; j++)
        {
            Vertex *new = (Vertex *)malloc(sizeof(Vertex));
            printf("Enter the %dth adjacent vertice of %d: ", j, i);
            scanf("%d", &new->data);
            new->link = NULL;
            if (adj[i] == NULL)
                adj[i] = new;
            else
                ptr->link = new;
            ptr = new;
        }
    }
}

void printGraph(Vertex **adj, int NUM_OF_VERTICES)
{
    for (int i = 0; i < NUM_OF_VERTICES; i++)
    {
        Vertex *temp = adj[i];
        if (temp == NULL)
            printf("There are no vertices adjacent to %d!\n", i);
        else
        {
            printf("Vertices adjacent to %d are: ", i);
            while (temp != NULL)
            {
                printf("%d  ", temp->data);
                temp = temp->link;
            }
            printf("\n");
        }
    }
}

void bfs(Vertex **adj, int NUM_OF_VERTICES, int start_vertex)
{
    int visited[NUM_OF_VERTICES];
    memset(visited, 0, NUM_OF_VERTICES * sizeof(int));
    enqueue(start_vertex);
    visited[start_vertex] = 1;
    while (front != NULL)
    {
        Vertex *ptr = adj[dequeue()];
        while (ptr != NULL)
        {
            int data = ptr->data;
            if (visited[data] == 0)
            {
                enqueue(data);
                visited[data] = 1;
                printf("%d  ", data);
            }
            ptr = ptr->link;
        }
    }
}

void dfs(Vertex **adj, int NUM_OF_VERTICES, int start_vertex)
{
}

int main(int argc, char *argv[])
{
    int NUM_OF_VERTICES;
    printf("Enter the number of vertices: ");
    scanf("%d", &NUM_OF_VERTICES);
    Vertex *adj[NUM_OF_VERTICES];
    for (int i = 0; i < NUM_OF_VERTICES; i++)
        adj[i] = NULL;
    readGraph(adj, NUM_OF_VERTICES);
    printGraph(adj, NUM_OF_VERTICES);
    int start, choice;
    printf("Select operation:\n"
           "1. BFS Traversal\n2. DFS Traversal\n"
           "3. Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the vertex to start traversal from: ");
        scanf("%d", &start);
        bfs(adj, NUM_OF_VERTICES, start);
        break;

    case 2:
        printf("Enter the vertex to start traversal from: ");
        scanf("%d", &start);
        dfs(adj, NUM_OF_VERTICES, start);
        break;

    case 3:
        return 0;

    default:
        printf("Invalid operation!\n");
        break;
    }
    return 0;
}