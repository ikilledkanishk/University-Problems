//Problem Defination: Suppose you have an Undirected Graph and your assignment is to traverse all vertices. Apply a suitable algorithm for this traversal.

//Source Code:

#include <stdio.h>

int graph[20][20], visited[20];
int n;

void BFS(int start)
{
    int queue[20], front = 0, rear = 0;
    int i, vertex;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

void DFS(int vertex)
{
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] && !visited[i])
            DFS(i);
    }
}

int main()
{
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex.\n");
        return 0;
    }

    BFS(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
