#include<bits/stdc++.h>

    static bool mycomp (Item a, Item b)
    {
        return (double)a.value/(double)a.weight > (double)b.value/(double)b.weight;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,mycomp);
        // for(int i=0;i<n;i++) cout<<arr[i].value<<" "<<arr[i].weight<<"\n";
        
        double val = 0.0;
        for(int i=0;i<n;i++)
        {
            if(W >= arr[i].weight) {
                val += arr[i].value;
                W -= arr[i].weight;
            }
            
            else{
                val += W * ((arr[i].value /(double)arr[i].weight));
                break;
            }
        }
        
        return val;
    }