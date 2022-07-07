#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //Write your code here.
    int count = 0;
    for(int i=0;i<arr.size();i++)
    {
        int x_r = 0;    
        for(int j = i;j<arr.size();j++){        
            x_r = x_r ^ arr[j];
            if(x_r == x) count++;
        }
    }
    
    return count;
}
//TC -> O(n^2)
//SC -> O(1)
//It will give TLE

// OPtimized approach
int subarraysXor(vector<int> &arr, int k)
{
    //Write your code here.
    int cnt = 0;
    int xr = 0;
    map<int,int>mp;
    for(int i=0;i<arr.size();i++){
       
        xr = xr ^ arr[i];
        if(xr == k) cnt++;
        
        if(mp.find(xr^k) != mp.end()) cnt += mp[xr^k];
        
        mp[xr]++;
    }
    
    return cnt;
}

//TC -> O(NlogN) as we have used ordered map so(logN) to search. If we use unordered_map then it will be O(N) because 
//      unordered map takes O(1) for searching but in worst case it can take O(N) for searching then TC will become 
//      (N^2) so to be in safer side we use map and TC become O(logN). 
