struct TrieNode{
    TrieNode *child[2];
};

class Trie{
    
    private: TrieNode *root;
 
    public:
       Trie(){
           root = new TrieNode();
       }
       
       int getMax(int num)
       {
           TrieNode *curr = root;
           int maxi = 0;
           
           for(int i=31;i>=0;i--)
           {
               int bit = (num >> i) & 1;
               
               if(curr->child[1-bit] != NULL)
               {
                   maxi = maxi | (1<<i);
                   curr = curr->child[1-bit];
               }
               else{
                  curr = curr->child[bit]; 
               }
           }
           
           return maxi;
       }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& arr) {
        
        int N = arr.size();       
        Trie op;
        
        for(int i=0;i<N;i++)
        {
            op.insert(arr[i]);
        }
        
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            ans = max(ans,op.getMax(arr[i]));
        }
        
        return ans;
    }
};



















