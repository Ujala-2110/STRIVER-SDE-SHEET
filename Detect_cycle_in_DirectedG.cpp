#include<bits/stdc++.h>

bool dfs(int x,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis)
{
    vis[x] = 1;
    dfsvis[x] = 1;   
    for (auto ch : adj[x])
    {
        if (!vis[ch])
        {
            if (dfs(ch, adj, vis, dfsvis)) return true;
        }
        else if (dfsvis[ch]) return true;
    }
    dfsvis[x] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int>adj[n+1];
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    
    vector<int> vis(n+1,0);
    vector<int>dfsvis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == 0)
        if(dfs(i,adj,vis,dfsvis)) return 1;
    }
    
    return 0;
}

//Using bfs

int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int>adj[v+1];
    unordered_map<int,int>indeg;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        indeg[v]++;
    }
   
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    int cnt = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[x])
        {
            indeg[it]--;
            if (indeg[it] == 0)
                q.push(it);
        }
    }

    
    if(cnt == v) return 0;
    else return 1;
}