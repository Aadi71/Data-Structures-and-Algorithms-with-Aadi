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
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.length();
        int k = 0;
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            k = word[i] - 'a';
            if(curr->children[k] == NULL) curr -> children[k] = new TrieNode();
            curr = curr -> children[k];
        }
        curr -> word = true;
    }
    
    bool search(string word) {
        int n = word.length();
        int k = 0;
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            k = word[i] - 'a';
            curr = curr -> children[k];
            if(curr == NULL) return false;
        }
        return curr -> word;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        int k = 0;
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            k = prefix[i] - 'a';
            curr = curr -> children[k];
            if(curr == NULL) return false;
        }
        return true;
    }
    TrieNode* root;
};
