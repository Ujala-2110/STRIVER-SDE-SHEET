#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    
       /*
        map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            if(mp[arr[i]] == 2) return arr[i];
        }
        */
    
    //Another approach
    int slow = arr[0];
    int fast = arr[0];
    
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);
    
    fast = arr[0];
    while(slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    
    return slow;
    
}
