#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){

	sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());

    priority_queue<pair<int, pair<int, int>>> pq;


    // 20 20 18 15 11 9 7 0
    // 17 16 16 13  7 7 5 3

    //desired
    // 37 37 36 36 36 36 35 34

    // 37 37 36 36 36 36 36 36 

    vector<int>ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    pq.push({a[0]+b[0], {0, 0}});
    vis[0][0] = 1;

    while(k--)
    {
        int top = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        ans.push_back(top);
        pq.pop();

        if(j+1 < n && vis[i][j+1] == 0)
        {
            pq.push({a[i] + b[j+1] ,{i , j+1}});
            vis[i][j+1] = 1;
        }

        if(i+1 < n && vis[i+1][j] == 0)
        {
            pq.push({a[i+1] + b[j] ,{i+1 , j}});
            vis[i+1][j] = 1;
        }
    }

    return ans;
}





































