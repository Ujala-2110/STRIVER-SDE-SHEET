#include <bits/stdc++.h> 

// bool compareInterval(vector<int> &a ,vector<int> &b)
// {
//     if(a[0] == b[0]){
//         if(a[1] >= b[1]) return a>b;
//         else return a<b;
//     }
//     else return a < b;
// }

vector<vector<int>> pairSum(vector<int> &nums, int target){
   // Write your code here.
    vector<vector<int>>res;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target)  
            res.push_back(vector<int>{min(nums[i],nums[j]),max(nums[i],nums[j])});
        }
    }
    sort(res.begin(),res.end());
    return res;
}