#include<bits/stdc++.h>

bool dfs(int node, int par , vector<int>adj[], vector<int>&vis)
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
           if(dfs(it,node,adj,vis)) return true;
        }
        else if(par != it) return true;
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == 0)
        {
           if(dfs(i,-1,adj,vis)) return "Yes";
        }
    }
    
    return "No";
}

//BFS

bool bfs(int x, vector<int>adj[], vector<int>&vis)
{
   queue<pair<int, int>> q;
    vis[x] = 1;
    q.push({x, -1});

    while (!q.empty())
    {
        int node = (q.front()).first;
        int par = (q.front()).second;
        q.pop();

        for (auto e : adj[node])
        {
            if (!vis[e])
            {
                vis[e] = 1;
                q.push({e, node});
            }
            else if (par != e) return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == 0)
        {
           if(bfs(i,adj,vis)) return "Yes";
        }
    }
    
    return "No";
}
