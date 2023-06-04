#include<bits/stdc++.h>
const int d = 256;
const int q = INT_MAX;
void rabinkarp(string &pattern,string &text,vector<int> &ans)
{
    int j;
    int h=1;
    int p=0; 
    int t=0; 
    int n=text.size();
    int m=pattern.size();

    for(int i=0;i<m-1;i++) h=(h*d)%q;
    
    for(int i=0;i<m;i++)
    {
        p=(d*p + pattern[i])%q;
        t=(d*t + text[i])%q;
    }

    // Slide the pattern over text one by one 
    for(int i=0;i<=n-m;i++)
    {
        if(p==t)
        {     
            bool flag = true;
            for(j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        
        if(i<n-m)
        {
            t=((d*(t-h*text[i]))+ text[i+m])%q;
            if(t<0) t=t+q;
        }
    }
}
vector<int> stringMatch(string &str, string &pat) {
   // Write your code here     
       vector<int> ans;       
       rabinkarp(pat,str,ans);
       return ans;
}