#include<bits/stdc++.h>

void Z_array(string & str,int z[])
{
    int n = str.length();
    int L = 0 , R = 0;
    
    for(int i=1;i<n;i++)
    {
        if(i > R)
        {
            L = R = i;
            while(R < n && str[R-L] == str[R]) R++;
            
            z[i] = R-L;
            R--;
        }
        
        else
        {
            int k = i-L;
            if(z[k] < R-i+1) z[i] = z[k];
            
            else
            {
                L = i;
                while(R < n && str[R-L] == str[R]) R++;
                
                z[i] = R-L;
                R--;
            }
        }
    }
}

int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    string concat = p +"$"+s;
    int l = concat.length();
    
    int z[l];
    Z_array(concat , z);
    
    int cnt = 0;
    for(int i=0;i<l;i++)
    if(z[i] == p.length()) cnt++;
    
    //Pattern found at index = i-pat.length()-1
    return cnt;
    
}