#include <bits/stdc++.h>

void func(int ind, int amt, vector<int> &cand, vector<vector<int>> &ans, vector<int> v)
{
    if (amt < 0 || ind == cand.size())
        return;
    if (amt == 0)
    {
        ans.push_back(v);
        return;
    }

    if (cand[ind] <= amt)
    {
        v.push_back(cand[ind]);
        func(ind, amt - cand[ind], cand, ans, v);
        v.pop_back();
    }
    
    func(ind + 1, amt, cand, ans, v);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<vector<int>> ans;
    vector<int> v;
    func(0, target, candidates, ans, v);
    return ans;
}