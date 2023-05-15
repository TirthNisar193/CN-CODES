#include<stdio.h>

int main(){

    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter the cost matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    int v;
    printf("Enter the source vertex: ");
    scanf("%d", &v);

    int dist[n];
    int path[n];

    for(int i=0; i<n; i++){
        if(i==v){
            dist[i] = 0;
        }
        else{
            dist[i] = 100;
        }
        path[i] = 0;
    }

    for(int i=0; i<n; i++){ // this for loop is for n iterations
        for(int u=0; u<n; u++){
            for(int v=0; v<n; v++){
                if(cost[u][v]!=100 && u!=v){
                    if(cost[u][v]+dist[u] < dist[v]){
                        dist[v] = cost[u][v] + dist[u];
                        path[v] = u;
                    }
                }
            }
        }
    }

    printf("\n\tDistance\tPath\n");

    for(int i=0; i<n; i++){
        printf("dist[%d]=%d\t p[%d]=%d\n", i, dist[i], i, path[i]);
    }
    
    return 0;
}
