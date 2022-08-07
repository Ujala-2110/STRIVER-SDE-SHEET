#include<bits/stdc++.h>

bool is_valid(int n , int m)
{
    if(n < 0 || m < 0) return false;
    return true;
}
int func(int i, int j,vector<vector<int>> &grid,vector<vector<int>>&dp)
{
    if(i == 0 && j == 0) return grid[0][0];
    if(dp[i][j] != -1) return dp[i][j];
    if(is_valid(i-1,j) && is_valid(i,j-1)) 
        return dp[i][j] = min(grid[i][j] + func(i-1,j,grid,dp), grid[i][j] +  func(i,j-1,grid,dp));
    else if(is_valid(i-1,j)) return dp[i][j] = grid[i][j] +  func(i-1,j,grid,dp);
    else return dp[i][j] = grid[i][j] +  func(i,j-1,grid,dp);
    
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<int>prev(m,0);
    
    for(int i=0;i<n;i++)
    {
        vector<int>cur(m,0);
        for(int j=0;j<m;j++)
        {
            if(i == 0 && j == 0) cur[j] = grid[0][0];
            else{
                if(is_valid(i-1,j) && is_valid(i,j-1)) 
                cur[j] = min(grid[i][j] + prev[j], grid[i][j] + cur[j-1]);
                else if(is_valid(i-1,j)) cur[j] = grid[i][j] +  prev[j];
                else cur[j] = grid[i][j] +  cur[j-1];
            }
        }
        prev = cur;
    }
    
    return prev[m-1];
}




