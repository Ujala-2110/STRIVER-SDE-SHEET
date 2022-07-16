#include <bits/stdc++.h>
int findMinVertex(vector<int>&distance,vector<bool>&visited,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex == -1 || distance[i]<distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}
vector<int> dijkstra(vector<vector<int>> &vec, int n, int e, int source) {
    int **graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int[n];
        for(int j=0;j<n;j++){
            graph[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        graph[u][v] = w;
        graph[v][u] = w;
    }
    vector<int> distance(n,INT_MAX);
    vector<bool> visited(n,false);
    distance[source] = 0;
    for(int i=0;i<n;i++){
        int mv = findMinVertex(distance,visited,n);
        visited[mv] = true;
        for(int j=0;j<n;j++){
            if(graph[mv][j]!=0 && !visited[j]){
                int dist = distance[mv] + graph[mv][j];
                if(dist<distance[j])
                    distance[j] = dist;
            }
        }
    }
    return distance;
}






