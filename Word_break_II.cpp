#include<bits/stdc++.h>

void func(int ind,string &s, unordered_set<string>&st, vector<string>&ans, string str)
{
    if(ind == s.size()){
        str.pop_back();
        ans.push_back(str);
        return;
    }

    string tmp = "";
    for(int i=ind;i<s.size();i++)
    {
        tmp.push_back(s[i]);
        if(st.find(tmp) != st.end()) func(i+1,s,st,ans,str+tmp+" ");
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {

    vector<string> ans;
    unordered_set<string>st;
    for(auto it : wordDict) st.insert(it);

    func(0,s,st,ans,"");
    return ans;
}