#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
    
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++) dp[i][0] = 1;
    for(int j=0;j<n;j++) dp[0][j] = 1;

    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }

    return dp[m-1][n-1];
}

//Space Optimised
int uniquePaths(int m, int n) {
	// Write your code here.
    
    vector<int>prev(n,0);
    for(int i=0;i<m;i++)
    {
        vector<int>cur(n,0);
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0) cur[j] = 1;
            
            else{
                int up = 0, left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = cur[j-1];
                
                cur[j] = up + left;
            }
            
        }
        
        prev = cur;
    }

    return prev[n-1];
}

int uniquePaths(int m, int n) {
	// Write your code here.
        int N = m+n-2;
        int r = m-1;
        double res = 1;

        for(int i=1;i<=r;i++)
        res = res * (N - r +i)/i;

        return (int)res;
}

// TC -> O(n-1) or O(m-1)
// SC -> O(1)