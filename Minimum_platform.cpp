#include<bits/stdc++.h>

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	sort(arr,arr+n);
    	sort(dep,dep+n);
        
        int plat = 1;
        int res = 1;
        int i = 1 , j = 0;
        while(i < n && j < n)
        {
            if(arr[i] <= dep[j]){
                plat++;
                i++;
            }
            
            else{
                plat--;
                j++;
            }
            
            res = max(res,plat);
        }
        
        return res;
    }
};












