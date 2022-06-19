#include <bits/stdc++.h> 

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    sort(arr1.begin(),arr1.end());
    int k = 0, i=n, j=0;
    while(i < (m+n) && j < n)
    {
        if(arr1[i] <= arr2[j]){
            arr1[k] = arr1[i];
            k++;
            i++;
        }
        else {
            arr1[k] = arr2[j];
            j++;
            k++;
        }
    }
    
    while(i < (m+n)){
        arr1[k] = arr1[i];
        i++;
        k++;
    }
    
    while(j < n){
        arr1[k] = arr2[j];
        j++;
        k++;
    }
    
    return arr1;
}