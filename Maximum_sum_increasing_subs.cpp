// Q-> Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array 
// such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence

// Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
// Output: 106
// Explanation:The maximum sum of a
// increasing sequence is obtained from
// {1, 2, 3, 100}

#include<bits/stdc++.h>

//Memoization
// int func(int ind,int pr, int arr[], int n,vector<vector<int>>&dp)
// {
//     if(ind == n) return 0;

//     if(dp[ind][pr+1] != -1) return dp[ind][pr+1];
//     int sum = func(ind+1, pr, arr, n,dp);

//     if(pr == -1 || arr[ind] > arr[pr])
//         sum = max(sum , arr[ind] + func(ind+1, ind , arr, n,dp));

//     return dp[ind][pr+1] = sum;
// }
    
//Reverse Memoization

int func(int ind,int pr, vector<int>&arr, int n,vector<vector<int>>&dp)
{
    if(ind < 0) return 0;

    if(dp[ind][pr] != -1) return dp[ind][pr];
    int sum = func(ind-1, pr, arr, n,dp);

    if(pr == n || arr[ind] < arr[pr])
    sum = max(sum , arr[ind] + func(ind-1, ind , arr, n,dp));

    return dp[ind][pr] = sum;
}
// vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
// return func(n-1,n,arr,n,dp);

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	// Write your code here
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int ind=n-1;ind>=0;ind--)
    {
        for(int pr = ind-1; pr >=-1 ;pr--)
        {
            int sum = dp[ind+1][pr+1];

            if(pr == -1 || arr[ind] > arr[pr])
                sum = max(sum , arr[ind] + dp[ind+1][ind+1]);


            dp[ind][pr+1] = sum;
        }
    }

    return dp[0][0];
}

//Optimised
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	// Write your code here
    vector<int>dp(n+1,arr[0]);
    
    for(int i=1;i<n;i++)
    {
        int ans = arr[i];
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i]) ans = max(ans,arr[i]+dp[j]);
        }
        
        dp[i] = ans;
    }
    
    return *max_element(dp.begin(),dp.end());
}

