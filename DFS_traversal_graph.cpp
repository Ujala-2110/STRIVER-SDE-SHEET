#include<bits/stdc++.h>

void dfs(int x, vector<int>&vis, vector<int>adj[], vector<int>&temp)
{
    temp.push_back(x);
    vis[x] = 1;
    
    for(auto it : adj[x])
    if(vis[it] == 0) dfs(it,vis,adj,temp);
    
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>adj[V];
    vector<int>vis(V,0);
    vector<vector<int>>ans;
    for(int i=0; i<E; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i=0;i<V;i++)
    {
        if(vis[i] == 0){
            vector<int>temp;
            dfs(i,vis,adj,temp);
            ans.push_back(temp);
        }
    }
    
    return ans;
}