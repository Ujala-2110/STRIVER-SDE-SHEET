#include<bits/stdc++.h>

void fillLps(string &p, int lps[])
{
    int n = p.length();
    int len = 0;
    lps[0] = 0;
    int i=1;
    while(i < n)
    {
        if(p[i] == p[len]){
            len++;
            lps[i] = len;
            i++;
        }
        
        else{
            if(len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else len = lps[len-1];
        }
    }
}

bool findPattern(string p, string s)
{
    // Write your code here.
    int n = s.length();
    int m = p.length();
    
    int i = 0, j = 0;
    int lps[m];
    fillLps(p,lps);
    
    while(i < n)
    {
        if(s[i] == p[j]){
            i++;
            j++;
        }
        
        if(j == m) return true;
        
        else if(i < n && p[j] != s[i]){
            if(j == 0) i++;
            else j = lps[j-1];
        }
    }
    
    return false;
}

