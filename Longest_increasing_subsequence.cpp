#include <bits/stdc++.h>

int longestIncreasingSubsequence(int nums[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = dp[ind + 1][prev_ind + 1];

            if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                len = max(len, 1 + dp[ind + 1][ind + 1]);

            dp[ind][prev_ind + 1] = len;
        }
    }

    return dp[0][-1 + 1];
}


//Using Binary Search
int longestIncreasingSubsequence(int nums[], int n)
{
    // Write Your Code here
    vector<int> temp;

    temp.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            len++;
        }

        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }

    return len;
}
