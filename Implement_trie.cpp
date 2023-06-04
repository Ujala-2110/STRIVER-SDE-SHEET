/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Trie {    
    
   private:
    struct TrieNode{
        TrieNode *child[26];
        bool isEnd;
    };
    
    TrieNode *root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        
        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            
            if(curr -> child[index] == NULL) curr->child[index] = new TrieNode(); 
            
            curr = curr->child[index];
        }
        
        curr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        TrieNode *curr = root;
        
        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            
            if(curr -> child[index] == NULL) return false;
            
            curr = curr->child[index];
        }
        
        return curr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        
        for(int i=0;i<prefix.length();i++)
        {
            int index = prefix[i] - 'a';
            
            if(curr -> child[index] == NULL) return false;
            
            curr = curr->child[index];
        }
        
        return true;
    }
};