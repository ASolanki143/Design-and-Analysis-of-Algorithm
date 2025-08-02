#include<stdio.h>

#define V 8

int queue[V];
int l = -1, r = -1;

void printQueue(){
    for(int i = l ; i <= r ; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int isEmpty(){
    return l == -1;
}

int isFull(){
    return r >= V - 1;
}

void enqueue(int data){
    if(isFull()){
        return;
    }
    r++;
    queue[r] = data;
    if(l == -1) l = 0;
}

int dequeue(){
    if(isEmpty()){
        return -1;
    }
    int data = queue[l];
    l++;
    if(l == V){
        l = r = -1;
    }
    return data;
}

void bfs(int graph[V][V]){
    int visited[V] = {0};

    visited[0] = 1;
    enqueue(0);

    while(!isEmpty()){
        int u = dequeue();
        printf("%d ",u + 1);
        for(int i = 0 ; i < V ; i++){
            if(visited[i] == 0 && graph[u][i] != 0){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

void main(){
    int graph[V][V] = {
        {0,1,1,1,0,0,0,0},
        {1,0,1,0,1,1,0,0},
        {1,1,0,0,0,1,0,0},
        {1,0,0,0,0,0,1,1},
        {0,1,0,0,0,1,0,0},
        {0,1,1,0,1,0,0,0},
        {0,0,0,1,0,0,0,1},
        {0,0,0,1,0,0,1,0}
    };
    bfs(graph);
}