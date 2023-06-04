#include <bits/stdc++.h> 

int parent(int i)
{
    return (i-1)/2;
}

void insert(int x , vector<int>&heap)
{
    heap.push_back(x);
    int size = heap.size();

    for(int i=size-1; i!=0 && heap[parent(i)] > heap[i];)
    {
        swap(heap[i],heap[parent(i)]);
        i = parent(i);
    }
}

void Minheapify(int i, vector<int>&heap)
{
    int size = heap.size();

    int lt = 2*i+1;
    int rt = 2*i+2;
    
    int smallest = i;

    if(lt < size && heap[lt] < heap[i]) smallest = i;
    if(rt < size && heap[rt] < heap[smallest]) smallest = rt;

    if(smallest != i)
    {
        swap(heap[i], heap[smallest]);
        Minheapify(smallest,heap);
    }
}

void delete_(vector<int>&ans , vector<int>&heap)
{
    if(heap.size() == 0) return;

    if(heap.size() == 1) {ans.push_back(heap[0]); heap.pop_back();}

    if(heap.size() == 0) return;

    ans.push_back(heap[0]);

    swap(heap[0] , heap[heap.size()-1]);
    heap.pop_back();

    Minheapify(0,heap);
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    
    vector<int>heap;
    vector<int>ans;

    for(int i=0;i<q.size();i++)
    {
        //Type -> 1

        if(q[i].size() == 2)
        {
            insert(q[i][1],heap);
        }

        //Type -> 2
        
        else{
            delete_(ans,heap);
        }
    }

    return ans;
}



































