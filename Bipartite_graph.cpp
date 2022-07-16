#include<bits/stdc++.h>
bool bfs(int x,vector<int>adj[],vector<int>&col,vector<int>&vis){
    queue<int>q;
    q.push(x);
    col[x]=1;
    vis[x]=1;
    
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto ch:adj[f]){
            if(!vis[ch]){
                col[ch]=!col[f];
                q.push(ch);
                vis[ch] = 1;
            }
            else if(col[ch]==col[f]) return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n=edges.size();
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int>col(n,0);
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(!bfs(i,adj,col,vis)){
                return false;
            }
        }
    }
    return true;
}
