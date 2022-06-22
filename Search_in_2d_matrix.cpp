#include <bits/stdc++.h> 
#include <vector>

bool BinSearch(vector<int> & arr,int n,int tar)
{
    int l = 0;
    int h = n-1;
    
    while(l <= h)
    {
        int mid = (l+h)/2;
        
        if(arr[mid] == tar) return true;
        
        else if(arr[mid] > tar) h = mid-1;
        else l = mid+1;
    }
    
    return false;
}
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
     bool is_pr = false;
     for(int i=0;i<m;i++)
     {
         is_pr |= BinSearch(mat[i],n,target);
     }
    
    return is_pr;
}

//Another approach

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
     int i=0 , j = n-1;
     while(i<m && j>=0)
     {
        if(mat[i][j] == target) return true;
        
        else if(mat[i][j] > target) j--;
        
        else i++;
     }
    
    return false;
}

//Another approach (Binary Seach in 2D matrix)
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
   int l  = 0;
   int h = m*n-1;
    
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(mat[mid/n][mid%n] == target) return true;
        
        else if(mat[mid/n][mid%n] > target) h = mid-1;
        
        else l = mid+1;
    }
    
    return false;
}

//TC -> O(log n*m)
//SC -> O(1)