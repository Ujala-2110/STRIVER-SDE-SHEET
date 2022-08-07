#include<bits/stdc++.h>
bool func(int i, int k ,vector<int>&arr,vector<vector<int>>&dp)
{
    if(k == 0) return true;
    if(i < 0) return false;
    if(dp[i][k] != -1) return dp[i][k];
    int nottake = func(i-1,k,arr,dp);
    int take = 0;
    if(arr[i] <= k) take = func(i-1,k-arr[i],arr,dp);
    return dp[i][k] = take || nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
//     vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    vector<int>prev(k+1,0),cur(k+1,0);
    for(int i = 0 ; i<=n;i++) prev[0] = 1;
    for(int j = 1 ; j<=k;j++) prev[j] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            int nottake = prev[j];
            int take = 0;
            if(arr[i-1] <= j) take = prev[j-arr[i-1]];
            cur[j] = take || nottake;
        }
        prev = cur;
    }
    return prev[k];
}