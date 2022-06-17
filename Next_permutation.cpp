#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int index1 = 0,index2 = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(permutation[i-1] < permutation[i])
        {
           index1 = i-1;
           break;
        }
    }
    
    if(index1 == -1) 
    {
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }

    
    for(int i=n-1;i>=0;i--)
    {
        if(permutation[i] > permutation[index1]) 
        {
            index2 = i;
            break;
        }
    }
    
    swap(permutation[index1],permutation[index2]);
    reverse(permutation.begin()+(index1+1) , permutation.end());
    
    return permutation;
}