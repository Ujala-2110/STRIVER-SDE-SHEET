#include<bits/stdc++.h>

void solve(vector<int>&s, int index, vector<vector<int>>&res)
{
    if (index == s.size())
    {
        res.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
        
    }
}

vector<vector < int>> permute(vector<int> &nums) {
    
    vector<vector<int>>res;
    solve(nums,0,res);
    
    return res;
}