//Problem Definition: Implement MST Problem using appropriate algorithm design technique.
//Source Code:

#include <stdio.h>

struct Edge
{
    int src, dest, weight;
};

int parent[100];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    int n, e, i, j, totalCost = 0;
    struct Edge edge[100], temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter source, destination and weight of each edge:\n");

    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edge[i].src, &edge[i].dest, &edge[i].weight);

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < e - 1; i++)
    {
        for (j = i + 1; j < e; j++)
        {
            if (edge[i].weight > edge[j].weight)
            {
                temp = edge[i];
                edge[i] = edge[j];
                edge[j] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0, j = 0; i < e && j < n - 1; i++)
    {
        int u = find(edge[i].src);
        int v = find(edge[i].dest);

        if (u != v)
        {
            printf("%d - %d : %d\n",
                   edge[i].src, edge[i].dest, edge[i].weight);

            totalCost += edge[i].weight;
            unionSet(u, v);
            j++;
        }
    }

    if (j != n - 1)
        printf("MST does not exist. Graph is disconnected.\n");
    else
        printf("Minimum Cost = %d\n", totalCost);

    return 0;
}
