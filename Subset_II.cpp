#include <bits/stdc++.h>

void func(int ind, vector<int> &v, vector<vector<int>> &ans, vector<int> &nums)
{
    ans.push_back(v);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        v.push_back(nums[i]);
        func(i + 1, v, ans, nums);
        v.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{

    vector<vector<int>> ans;
    vector<int> v;

    sort(nums.begin(), nums.end());
    func(0, v, ans, nums);
    return ans;
}
