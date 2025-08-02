#include <stdio.h>
#include <limits.h>

#define V 5
#define E 9

int findMinKey(int visited[], int distance[])
{
    int min = INT_MAX;
    int key = -1;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && distance[i] < min)
        {
            min = distance[i];
            key = i;
        }
    }

    return key;
}

void dijkstra(int graph[V][V])
{
    int distance[V];
    int visisted[V];

    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        visisted[i] = 0;
    }

    distance[0] = 0;

    for (int i = 0; i < V; i++)
    {
        int u = findMinKey(visisted, distance);
        visisted[u] = 1;

        for (int j = 0; j < V; j++)
        {
            if (visisted[j] == 0 && graph[u][j] != 0)
            {
                if (distance[u] + graph[u][j] < distance[j])
                {
                    distance[j] = distance[u] + graph[u][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("%d ", distance[i]);
    }
}

void main()
{
    // int graph[V][V] = {
    //     {0,1,5,0,0,0},
    //     {1,0,1,2,4,0},
    //     {5,1,0,0,5,0},
    //     {0,2,0,0,7,6},
    //     {0,4,5,7,0,2},
    //     {0,0,0,6,2,0}
    // };

    int graph[5][5] = {
        // 0   1   2   3    4
        {0, 10, 0, 30, 100}, // 0
        {10, 0, 50, 0, 0},   // 1
        {0, 50, 0, 20, 10},  // 2
        {30, 0, 20, 0, 60},  // 3
        {100, 0, 10, 60, 0}  // 4
    };

    dijkstra(graph);
}