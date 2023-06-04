#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int N, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int, int>> adj[N+1];
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        int a = g[i].first.first;
        int b = g[i].first.second;
        int wt = g[i].second;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    int parent[N+1];
    int key[N+1];
    bool mstset[N+1];

    for (int i = 0; i <= N; i++)
    {
        parent[i] = -1;
        key[i] = 1e5;
        mstset[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-Heap

    key[1] = 0; // Starting node
    parent[1] = -1;
    pq.push({0, 1});

    for (int count = 1; count < N ; count++) // N-1 edges in MST
    {
        int u = pq.top().second;
        pq.pop();

        mstset[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (mstset[v] == false && weight < key[v])
            {
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = weight;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=N; i++) ans.push_back({{parent[i], i}, key[i]});
    
    return ans;

}
