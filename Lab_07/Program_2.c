#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[V] = {0};  // Track selected vertices
    selected[0] = 1;        // Start from vertex 0

    int edges = 0;

    printf("Edge \tWeight\n");

	int i,j;
    while (edges < V - 1) {
        int min = INT_MAX;
        int x = 0, y = 0;

        for (i = 0; i < V; i++) {
            if (selected[i] == 1) {
                for (j = 0; j < V; j++) {
                    if (selected[j] == 0 && graph[i][j] != 0) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d \t%d\n", x, y, graph[x][y]);
        selected[y] = 1;
        edges++;
    }

    return 0;
}

