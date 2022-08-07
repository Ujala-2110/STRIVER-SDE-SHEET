#include<bits/stdc++.h>
long func(int amt, int *coins, int i,vector<vector<long>>&dp)
{
    if(amt == 0) return 1;
    if(i < 0) return 0;
    if(dp[i][amt] != -1) return dp[i][amt];
    if(amt >= coins[i]) return dp[i][amt] = func(amt-coins[i],coins,i,dp) + func(amt,coins,i-1,dp);
    else return dp[i][amt] = func(amt,coins,i-1,dp);
}

long countWaysToMakeChange(int *coins, int n, int amount)
{
    //Write your code here
//     vector<vector<long>>dp(n+1,vector<long>(amount+1,0));
        vector<long>prev(amount+1,0);
        for(int i=0;i<=amount;i++) if(i%coins[0]==0) prev[i]=1;

        
    for(int i=1;i<n;i++)
    {
        vector<long>cur(amount+1,0);
        for(int amt = 0; amt <= amount; amt++)
        {
            if(amt >= coins[i]) cur[amt] = cur[amt-coins[i]] + prev[amt];
            else cur[amt] = prev[amt];
        }
        prev = cur;
    }
    
    return prev[amount];
}




