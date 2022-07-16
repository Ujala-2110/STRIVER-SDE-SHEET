#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int>adj[v];
    unordered_map<int,int>indeg;
    for(int i=0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        indeg[v]++;
    }
    vector<int>res;
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        res.push_back(f);
        
        for(auto ch : adj[f])
        {
            indeg[ch]--;
            if(indeg[ch] == 0)
            {
                q.push(ch);
            }
        }
    }
    
    return res;
    
}