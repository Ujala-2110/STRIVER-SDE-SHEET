#include<bits/stdc++.h>
#define INF 1000000000
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    
    vector<vector<int>> matrix(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        matrix[u][v] = wt;
    }

    // Floyd warshall algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][k] != INF && matrix[k][j] != INF) // To handle negative weight
                    matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));//This formula is the heart of the Floyd–Warshall algorithm.
            }
        }
    }
    return matrix[src][dest];
}