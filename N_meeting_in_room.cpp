#include<bits/stdc++.h>

class Solution
{
    public:
    
    static bool mycom(pair<int,int>&a , pair<int,int>&b)
    {
        return a.second<b.second;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> meet;
        
        for(int i=0;i<n;i++)
        {
            meet.push_back({start[i],end[i]});
        }
        
        sort(meet.begin(),meet.end(),mycom);
        // for(auto it : meet) cout<<it.first<<" "<<it.second<<"\n";
        
        int st = meet[0].second;
        int cnt = 1;
        
        for(int i=1;i<n;i++)
        {
            if(meet[i].first > st){
                cnt++;
                st = meet[i].second;
            }
        }
        
        return cnt;
    }
};
































