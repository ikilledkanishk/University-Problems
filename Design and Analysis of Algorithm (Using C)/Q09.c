//Problem Definition: Implement Single Source Shortest Path problem using proper algorithm design technique.
//Source Code:

#include <stdio.h>

#define INF 99999

int main()
{
    int n, source, i, j, count;
    int cost[100][100], dist[100], visited[100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for (count = 1; count < n; count++)
    {
        int min = INF, u = -1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && cost[u][i] != INF &&
                dist[u] + cost[u][i] < dist[i])
            {
                dist[i] = dist[u] + cost[u][i];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("Vertex %d : Unreachable\n", i);
        else
            printf("Vertex %d : %d\n", i, dist[i]);
    }

    return 0;
}
