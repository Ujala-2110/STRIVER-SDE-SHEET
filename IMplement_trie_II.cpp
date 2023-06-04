#include <bits/stdc++.h>
struct TrieNode
{
    TrieNode *children[26];
    int cp=0;
    int end=0;
};
TrieNode *root;
class Trie{
    public:

    Trie(){
        root=new TrieNode();
    }
    void insert(string &key){
        TrieNode *curr=root;
        for(int i=0;i<key.length();i++)
        {
            if(curr->children[key[i]-'a']==NULL)
                curr->children[key[i]-'a']=new TrieNode();
            curr=curr->children[key[i]-'a'];
            curr->cp+=1;
        }
        curr->end+=1;
    }

    int countWordsEqualTo(string &key){
        TrieNode *curr=root;
        for(int i=0;i<key.length();i++)
        {
            if(curr->children[key[i]-'a']==NULL)
                return 0;
            curr=curr->children[key[i]-'a'];
        }
        return curr->end;   
    }
    int countWordsStartingWith(string &key){
        TrieNode *curr=root;
        for(int i=0;i<key.length();i++)
        {
            if(curr->children[key[i]-'a']==NULL)
                return 0;
            curr=curr->children[key[i]-'a'];
        }
        return curr->cp;
    }
    void erase(string &word){
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++)
        {
            curr=curr->children[word[i]-'a'];
            curr->cp-=1;
        }
        curr->end-=1;
    }
};