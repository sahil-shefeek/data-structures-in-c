#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex
{
    int data;
    struct Vertex *link;
} Vertex;

void readGraph(Vertex **adj, int num)
{
    for (int i = 0; i < num; i++)
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

void printGraph(Vertex **adj, int num)
{
    for (int i = 0; i < num; i++)
    {
        Vertex *temp = adj[i];
        if (temp == NULL)
            printf("There are no vertices adjacent to %d!\n", i);
        else
        {
            printf("Vertices adjacent to %d are: ", i);
            while (temp != NULL)
            {
                printf("%d\t", temp->data);
                temp = temp->link;
            }
            printf("\n");
        }
    }
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
    return 0;
}