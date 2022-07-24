#include<bits/stdc++.h>

//Method -> 1
string longestCommonPrefix(vector<string> &strs, int n)
{
    // Write your code here
    string ans = "";
    bool flag = false;
    for(int i=0;i<strs[0].size();i++)
    {
        for(auto it : strs){
            if(strs[0][i] != it[i]){
                flag = true;
                break;
            } 
        }

        if(flag) break; 
        else ans += strs[0][i];   
    }

    return ans;

}

//Method -> 2
// 1.We first sort the array of strings.
// 2.Then, we choose the first and last string in the array. [They are supposed to be the most different among all the pairs of strings in the sorted array]
// 3.We just compare how many common characters match from index i = 0 of these two strings.

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";
    sort(arr.begin(),arr.end());
    string a = arr[0];
    string b = arr[n-1];
    
    for(int i=0;i<a.size();i++)
    {
        if(a[i] != b[i]) break;
        else ans += a[i];
    }
    
    return ans;
}