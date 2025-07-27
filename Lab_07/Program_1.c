#include<stdio.h>

struct Edge{
    int source;
    int dest;
    int weight;
};

void sortEdges(struct Edge edges[], int E){
    for(int i = 1; i < E; i++){
        struct Edge key = edges[i];

        int j = i - 1;

        while(j >= 0 && key.weight < edges[j].weight){
            edges[j + 1] = edges[j];
            j--;
        }

        edges[j + 1] = key;
    }
}

int find(int parent[], int i){
    if(parent[i] == i) return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int u, int v){
    parent[u] = v;
}

void kruskal(int V, int E, struct Edge edges[]){
    int parent[V];

    int edge = 0;
    struct Edge mst[V-1];

    for(int i = 0 ; i < V ; i++){
        parent[i] = i;
    }

    sortEdges(edges, E);

    for(int i = 0 ; i < E; i++){
        int u = edges[i].source;
        int v = edges[i].dest;

        int ucomp = find(parent,u);
        int vcomp = find(parent,v);

        if(ucomp != vcomp){
            mst[edge] = edges[i];
            unionSet(parent,ucomp,vcomp);
            edge++;
        }

        if(edge == V - 1) break;
    }

    int totalWeight = 0;

    printf("SRC | DEST | WEIGHT \n");
    for(int i = 0 ; i < V - 1 ; i++){
        printf("%d   | %d    | %d \n",mst[i].source,mst[i].dest,mst[i].weight);
        totalWeight += mst[i].weight;
    }

    printf("Total Weight = %d",totalWeight);
}

void main(){

    int V = 7;
    int E = 11;

    struct Edge edges[] = {
        {0,1,7},
        {0,3,5},
        {1,2,8},
        {1,3,9},
        {1,4,7},
        {2,4,5},
        {3,4,15},
        {3,5,6},
        {4,5,8},
        {4,6,9},
        {5,6,11}
    };

    kruskal(V,E,edges);

    return;
}