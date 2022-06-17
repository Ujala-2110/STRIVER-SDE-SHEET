#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0) cnt0++;
        else if(arr[i] == 1) cnt1++;
        else cnt2++;
    }
    
        int i= 0;  
        while(cnt0)
        {
            arr[i] = 0;
            cnt0--;
            i++;
        }
        
        while(cnt1)
        {
            arr[i] = 1;
            cnt1--;
            i++;
        }
        
        while(cnt2)
        {
            arr[i] = 2;
            cnt2--;
            i++;
        }
}

//TC -> O(2N)
//SC -> O(1)

void sort012(int *a, int n)
{
// Dutch national flag algorithm
    
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid <= high)
    {
        if(a[mid] == 0) 
            swap(a[low++],a[mid++]);
        
        else if(a[mid] == 1) mid++;
        
        else swap(a[mid],a[high--]);
    }
}

// TC -> O(N)
// SC -> O(1)
