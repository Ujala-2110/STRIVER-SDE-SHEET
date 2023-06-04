    #include<bits/stdc++.h>

    void func(int ind, int sum , vector<int>&arr, vector<int>&ans,int N)
    {
        if(ind == N){
            ans.push_back(sum);
            return;
        }
        
        func(ind+1,sum+arr[ind],arr,ans,N);
        func(ind+1,sum,arr,ans,N);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        
        func(0,0,arr,ans,N);
        sort(ans.begin(),ans.end());
        return ans;
    }