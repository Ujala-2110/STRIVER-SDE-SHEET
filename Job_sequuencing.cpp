#include<bits/stdc++.h>

// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool mycomp(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>v;
        sort(arr,arr+n,mycomp);
        // for(int i=0;i<n;i++) cout<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit<<"\n";
        
        int max_dd = INT_MIN;
        for(int i=0;i<n;i++){
            max_dd = max(arr[i].dead , max_dd);
        }
        
        int avail[max_dd+1];
        avail[0] = 1;
        for(int i=1;i<=max_dd;i++) avail[i] = 0;
      
        int cnt = 1;
        int ans = arr[0].profit;
        avail[arr[0].dead] = 1;
        
        for(int i=1;i<n;i++)
        {
            if(avail[arr[i].dead] == 0) {
                avail[arr[i].dead] = 1;
                ans += arr[i].profit;
                cnt++;
            }
            
            else{
                while(avail[arr[i].dead] != 0 && arr[i].dead != 0)
                {
                    arr[i].dead--;
                }
                
                if(avail[arr[i].dead] == 0 && arr[i].dead != 0){
                     avail[arr[i].dead] = 1;
                     ans += arr[i].profit;
                     cnt++;
                }
            }
        }
        
        v.push_back(cnt);
        v.push_back(ans);
        return v;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends