#include<bits/stdc++.h>

int vis[1005][1005];

int dx[8] = {1, 0, -1, 0,1,1,-1,-1};
int dy[8] = {0, 1, 0, -1,1,-1,-1,1};

bool isValid(int x, int y , int **grid,int n,int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;

    if (vis[x][y] == true || grid[x][y] == 0)
        return false;

    return true;
}

void dfs(int n,int m,int **grid, int x, int y)
{
    vis[x][y] = 1;

    for (int i = 0; i < 8; i++)
    {
        if (isValid(x + dx[i], y + dy[i],grid,n,m))
        dfs(n,m,grid,x + dx[i], y + dy[i]);
    }
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && vis[i][j] == 0)
            {
                dfs(n,m,arr,i, j);
                cnt++;
            }
        }
    }

    return cnt;
}
