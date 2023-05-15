// DIJKSTRA
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ver 8

int minimumdist(int distance[9],bool path[9]){
    int min=INT_MAX,u,i;
    for(i=0;i<9;i++){
        if(path[i]==false && distance[i]<=min){
            min=distance[i];
            u=i;
        }
    }
    return u;
}

void initializesinglesource(int distance[9],bool path[9],int source){
    int i;
    for(i=0;i<9;i++){
        distance[i]=INT_MAX;
        path[i]=false;
    }
    distance[source]=0;
}

void relax(int u,int v,int graph[9][9],int parent[9],int distance[9],bool path[9]){
    if(path[v]==false && graph[u][v]!=0 && distance[u]+graph[u][v]<distance[v]){
        distance[v]=distance[u]+graph[u][v];
        parent[v]=u;
    }
}

void dijkstra(int graph[9][9],int source){
    int v,distance[9],parent[9]={-1};
    int vertex=ver;
    bool path[9];

    initializesinglesource(distance,path,source);

    while(vertex!=0){
        int u = minimumdist(distance,path);
        path[u]=true;
        for(v=0;v<9;v++){
            relax(u,v,graph,parent,distance,path);
        }
        vertex--;
    }

    printf("\nvertex\tdistance from source\tparent");
    for(int i=0;i<9;i++){
        printf("\n%d\t\t%d\t\t\t\t\t\t%d",i,distance[i],parent[i]);
    }
}

int main() {
    int graph[9][9]= { { 0, 11, 0, 0, 0, 0, 0, 8, 0 },
                    { 11, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph,0);
    return 0;
}