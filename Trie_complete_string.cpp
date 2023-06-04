#include <bits/stdc++.h> 

struct TrieNode{
    TrieNode *child[26];
    bool isEnd = false;
};

TrieNode *root;

class Trie{
    public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string &key)
    {
        TrieNode *curr = root;

        for(int i=0;i<key.length();i++)
        {
            int index = key[i]-'a';
            if(curr->child[index] == NULL) curr->child[index] = new TrieNode();

            curr = curr->child[index];
        }
        curr->isEnd = true;
    }

    string search(string &key)
    {
        TrieNode *curr = root;
        string x = "";
        for(int i=0;i<key.length();i++)
        {
            int index = key[i]-'a';
            curr =curr->child[index];

            if(curr->isEnd == true) x += key[i];
            else return x;
        }

        return x;
    }

    string func(int n, vector<string>&a)
    {
        //insert
        for(int i=0;i<n;i++)
        {
            insert(a[i]);
        }

        //search
        int cnt = 0;
        string ans = "";
        for(auto it : a) {
            string res = search(it);
            if(res.size() > cnt){
                cnt = res.size();
                ans = res;
            }
            
            else if(res.size() == cnt)
            {
                if(res < ans) ans = res;
            }
        }

        if(ans.size() >= 1) return ans;
        else return "None";
    }

};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie op;
    return op.func(n,a);
}






