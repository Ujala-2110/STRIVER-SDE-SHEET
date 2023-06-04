#include<bits/stdc++.h>
bool dfs(int x,vector<int>adj[],vector<int>&col){

    if(col[x] == -1) col[x] = 0;
    for(auto ch : adj[x])
    {
        if(col[ch] == -1)
        {
            col[ch] = 1-col[x];
            if(!dfs(ch,adj,col)) return false;
        }
        
        else if(col[ch] == col[x]) return false;
    }
    
    return true;
    
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n=edges.size();
    vector<int>adj[n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int>col(n+1,-1);
    for(int i=0;i<n;i++){
        if(col[i] == -1){
            if(!dfs(i,adj,col)){
                return false;
            }
        }
    }
    return true;
}
