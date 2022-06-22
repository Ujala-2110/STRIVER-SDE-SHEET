#include <bits/stdc++.h> 

long long merge(long long arr[], long long temp[], int left ,int mid , int right)
{
    int i,j,k;
    long long inv_cnt = 0;
    i = left;
    j = mid;
    k = left;

    while(i <= (mid-1) && j <= right)
    {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            inv_cnt = inv_cnt + (mid - i);
        }
    }

    while(i <= (mid - 1))
    temp[k++] = arr[i++];

    while(j <= right)
    temp[k++] = arr[j++];

    for(i = left ; i<= right ; i++)
    arr[i] = temp[i];

    return inv_cnt;
}

long long merge_sort(long long *arr , long long temp[] , int left , int right)
{
    long long mid, inv_cnt = 0;

    if(right > left)
    {
        mid = (right + left)/2;
        inv_cnt += merge_sort(arr,temp,left,mid);
        inv_cnt += merge_sort(arr,temp,mid+1,right);

        inv_cnt += merge(arr,temp,left,mid+1,right);
    }

    return inv_cnt;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
   long long temp[n];
   long long ans = merge_sort(arr, temp , 0, n-1);
    
   return ans;
}