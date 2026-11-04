//Problem Defination: Implement Graph Colouring problem using proper algorithm design technique. 

//Source Code:

#include <stdio.h>

int graph[20][20], color[20];
int n, m;

int isSafe(int vertex, int c)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] && color[i] == c)
            return 0;
    }

    return 1;
}

int graphColoring(int vertex)
{
    int c, i;

    if (vertex == n)
    {
        for (i = 0; i < n; i++)
            printf("%d ", color[i]);

        printf("\n");
        return 1;
    }

    int found = 0;

    for (c = 1; c <= m; c++)
    {
        if (isSafe(vertex, c))
        {
            color[vertex] = c;

            found = graphColoring(vertex + 1) || found;

            color[vertex] = 0;
        }
    }

    return found;
}

int main()
{
    int i, j;

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

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (m < 1)
    {
        printf("Invalid number of colors.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        color[i] = 0;

    printf("Possible color assignments:\n");

    if (!graphColoring(0))
        printf("No solution exists.\n");

    return 0;
}
