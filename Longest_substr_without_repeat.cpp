#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Write your code here
    map<int,int>mpp;
    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n) {
        if (mpp.find(s[right]) != mpp.end())
            left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}