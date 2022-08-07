#include<bits/stdc++.h>
int func(int i, vector<int>&arr, int N,vector<vector<int>>&dp)
{
    if(i == 0 || N == 0) return 0;
    if(dp[i][N] != -1) return dp[i][N];
    int nottake = func(i-1,arr,N,dp);
    int take = 0;
    if(i <= N) take = arr[i-1] + func(i,arr,N-i,dp);
    
    return dp[i][N] = max(take , nottake);
}

int cutRod(vector<int> &arr, int n)
{
	// Write your code here.
    int maxlen = n;
//     vector<vector<int>>dp(n+1, vector<int>(maxlen+1, 0));
    vector<int>prev(maxlen+1,0), cur(maxlen+1,0);
//     for(int i=0;i<=n;i++) prev[i] = 0;
//     for(int i=0;i<=maxlen;i++) prev[0] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int N = 1;N<=maxlen;N++)
        {
            int nottake = prev[N];
            int take = 0;
            if(i <= N) take = arr[i-1] + cur[N-i];

            cur[N] = max(take , nottake);
        }
        prev = cur;
    }
    
    return prev[maxlen];
}
