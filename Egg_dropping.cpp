#include<bits/stdc++.h>
int helper(int n, int k, vector<vector<int>>& memo){
        if(k == 0 || k == 1) return k;
        if(n == 1) return k;
        
        if(memo[n][k] != -1) return memo[n][k];
        
        int mn = INT_MAX, low = 0, high = k, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            int left = helper(n-1, mid-1, memo);
            int right = helper(n, k-mid, memo);
            
            temp = 1 + max(left, right);
            
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;     
    
            mn = min(mn, temp); 
        }
        return memo[n][k] = mn;
    }

int cutLogs(int n, int k)
{
    // Write your code here.
    vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
    return helper(n,k,dp);
    
}
