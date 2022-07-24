// You are given a string ‘str’ of length 'N' and a string ‘pat’ of length 'M'. Your task is to find the starting index
//  of all the occurrences of ‘pat’ in str.
// You need to return a list of integers that denote the indices from which ‘pat’ is present in ‘str’(consider 0 based indexing).
// For example,
// Let str= “AABAACAADAABAABA”
// And pat= “AABA”
// We will return the array/list [0,9,12] as we can clearly see that from indices 0 9 and 12 we have the same pattern ‘pat’ in ‘str’

// Method->1
#include <bits/stdc++.h>
vector<int> stringMatch(string &str, string &pat)
{
    // Write your code here
    int n = str.length();
    int len = pat.length();

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (str.substr(i, len) == pat)
            v.push_back(i);
    }

    return v;
}

// Rabin-Karp
const int d = 256;
const int q = INT_MAX;
void rabinkarp(string &pattern, string &text, vector<int> &ans)
{
    int j;
    int h = 1;
    int p = 0;
    int t = 0;
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i < m - 1; i++) h = (h * d) % q; //To compute (d^(m-1))%q

    //Compute Po and To
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++)
    {
        //Check for spurious hit
        if (p == t)
        {
            bool flag = true;
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(i);
        }

        //Computing ti+1 using ti
        if (i < n - m)
        {
            t = ((d * (t - h * text[i])) + text[i + m]) % q;
            if (t < 0) t = t + q;
        }
    }
}
vector<int> stringMatch(string &str, string &pat)
{
    // Write your code here
    vector<int> ans;
    rabinkarp(pat, str, ans);
    return ans;
}