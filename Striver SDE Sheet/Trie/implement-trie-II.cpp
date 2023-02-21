// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?

class TrieNode{
    public:
    int countWords;
    int countPrefix;
    TrieNode *children[26];
    TrieNode(){
        countWords = 0;
        countPrefix = 0;
        for(int i = 0; i<26; i++) children[i] = NULL;
    }
};

class Trie{
    public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        int n = word.length();
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            int k = word[i] - 'a';
            if(curr -> children[k] == NULL){
                curr -> children[k] = new TrieNode();
            }
            curr = curr -> children[k];
            curr -> countPrefix++;
        }
        curr -> countWords++;
    }

    int countWordsEqualTo(string &word){
        int n = word.length();
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            int k = word[i] - 'a';
            if(curr -> children[k] == NULL) return 0;
            curr = curr -> children[k];
        }
        return curr -> countWords;
    }

    int countWordsStartingWith(string &word){
        int n = word.length();
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            int k = word[i] - 'a';
            if(curr -> children[k] == NULL) return 0;
            curr = curr -> children[k];
        }
        return curr -> countPrefix;
    }

    void erase(string &word){
        int n = word.length();
        TrieNode* curr = root;
        for(int i = 0; i<n; i++){
            int k = word[i] - 'a';
            curr = curr -> children[k];
            curr -> countPrefix--;
        }
        curr -> countWords--;
    }
};
