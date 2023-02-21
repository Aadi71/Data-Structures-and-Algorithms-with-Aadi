// https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode{
    public:
    bool word;
    TrieNode *children[26];
    TrieNode(){
        word = false;
        for(int i = 0; i<26; i++) children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.length();
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            int k = word[i] - 'a';
            if(curr -> children[k] == NULL) curr -> children[k] = new TrieNode();
            curr = curr -> children[k];
        }
        curr -> word = true;
    }
    
    bool search(string word) {
        int n = word.length();
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            int k = word[i] - 'a';
            if(curr -> children[k] == NULL) return false;
            curr = curr -> children[k];
        }
        return curr -> word;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            int k = prefix[i] - 'a';
            if(curr -> children[k] == NULL) return false;
            curr = curr -> children[k];
        }
        return true;
    }
};
