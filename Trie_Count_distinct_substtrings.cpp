
struct TrieNode {
    TrieNode *child[26];
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    TrieNode *root = new TrieNode();
    int cnt = 0;
    for(int i=0;i<s.length();i++)
    {
        TrieNode *curr = root;
        for(int j=i;j<s.length();j++)
        {
           if(curr->child[s[j]-'a'] == NULL)
           {
               cnt++;
               curr->child[s[j]-'a'] = new TrieNode();
           }
            
            curr = curr->child[s[j]-'a'];
        }
    }
    
    return cnt+1;
}














