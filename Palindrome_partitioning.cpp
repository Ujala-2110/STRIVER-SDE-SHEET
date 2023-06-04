#include<bits/stdc++.h>

void func(int ind,vector<int>& cand,int amt, vector<vector<int>>&ans,vector<int>&v)
{
    if(amt == 0){
        ans.push_back(v);
    }
    if(amt < 0) return;
    for(int i=ind;i<cand.size();i++)
    {
        if(i != ind && cand[i] == cand[i-1]) continue;
        
        v.push_back(cand[i]);
        func(i+1,cand,amt-cand[i],ans,v);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {        
    vector<vector<int>>ans;
    vector<int>v;
    sort(candidates.begin(),candidates.end());
    func(0,candidates,target,ans,v);
    return ans;
}