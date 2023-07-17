#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int minwtg(int dist[], int visited[])
{
    int min, i, k = -1;
    min = INT_MAX;
    for (i = 0; i < 9; i++)
    {
        if (visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            k = i;
        }
    }
    return k;
}

void display(int dist[])
{
    int i;
    printf("Vertex Distance from Source\n");
    for (i = 0; i < 9; i++)
    {
       printf("%d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[9][9], int u)
{
    int dist[9], visited[9];
    int i, j;

    for (i = 0; i < 9; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[u] = 0;

    for (j = 0; j < 8; j++)
    {
        int k = minwtg(dist, visited);
        visited[k] = 1;

        for (i = 0; i < 9; i++)
        {
            if (visited[i] == 0 && graph[k][i] != 0)
            {
                if ((dist[k] + graph[k][i]) < dist[i])
                {
                    dist[i] = dist[k] + graph[k][i];
                }
            }
        }
    }
    display(dist);
}

int main()
{
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}
