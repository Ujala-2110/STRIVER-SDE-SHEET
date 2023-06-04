#include<bits/stdc++.h>

class Solution{
public:
    
    bool is_valid(int node,bool graph[101][101] , int n, int m, int color[], int col)
    {
        for(int k=0;k<n;k++)
        {
            if(node != k && graph[k][node] == 1 && color[k] == col) return false;
        }
        
        return true;
    }
    
    bool Solve(int node, bool graph[101][101],int m, int n , int color[])
    {
        if(node == n) return true;
        
        for(int i=1;i<=m;i++)
        {
            if(is_valid(node,graph,n,m,color,i))
            {
                color[node] = i;
                
                if(Solve(node+1,graph,m,n,color)) return true;
                
                color[node] = 0;
            }
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        
        if(Solve(0,graph,m,n,color)) return true;
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //that no two adjacent vertices of graph are coloured with same colour.
// bool isSafe(int node,int color[], bool graph[101][101], int n , int col)
// {
//     for(int k=0;k<n;k++){
//         if(k!=node && graph[k][node]==1 && color[k] == col){
//             return false;
//         }
//     }
//     return true;
// }

// bool solve(int node,int color[],int m,int N, bool graph[101][101])
// {
//     if(node==N){
//         return true;
//     }
    
//     for(int i=1;i<=m;i++){
//         if(isSafe(node,color,graph,N,i)){
//             color[node]=i;
//         if(solve(node+1,color,m,N,graph)) return true;
//         color[node] = 0;
//         }
//     }
//     return false; 
// }

// bool graphColoring(bool graph[101][101], int m, int V)
// {
//     // your code here
//     int color[V]={0};
//     if(solve(0,color,m,V,graph)) return true;
    
//     return false;
// }
};