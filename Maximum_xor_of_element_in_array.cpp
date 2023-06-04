struct TrieNode{
    TrieNode *child[2];
};

class Trie{
    
    private: TrieNode *root;
 
    public:
       Trie(){
           root = new TrieNode();
       }
       
       void insert(int num)
       {
           TrieNode *curr = root;
           for(int i=31;i>=0;i--)
           {
               int bit = (num >> i) & 1;
               
               if(curr->child[bit] == NULL) curr->child[bit] = new TrieNode();
               
               curr = curr->child[bit];
           }
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>oq;
        
        int q = queries.size();
        for(int i=0;i<q;i++)
        {
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        
        sort(oq.begin(),oq.end());
        
        vector<int>ans(q,0);
        int ind = 0;
        int n = nums.size();
        
        Trie op;
        
        for(int i=0;i<q;i++)
        {
            int ai = oq[i].first;
            int xi = oq[i].second.first;
            int qind = oq[i].second.second;
            
            while(ind < n && nums[ind] <= ai)
            {
                op.insert(nums[ind]);
                ind++;
            }
            
            if(ind == 0) ans[qind] = -1;
            else ans[qind] = op.getMax(xi);
        }
        
        return ans;
    }
};

















