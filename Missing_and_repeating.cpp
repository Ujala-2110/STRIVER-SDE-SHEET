#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    //Write your code here    
	pair<int,int>ans;

    map<int,int>mp;
    
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(mp[i] == 0) ans.first = i;
        else if(mp[i] == 2) ans.second = i;
    }
    
    return ans;
    
}
