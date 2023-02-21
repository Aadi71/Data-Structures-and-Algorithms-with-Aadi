// https://leetcode.com/problems/map-sum-pairs/

class TrieNode{
    public:
    int value;
    TrieNode *children[26];
    TrieNode(){
        value = 0;
        for(int i = 0; i<26; i++) children[i] = NULL;
    }
};

class MapSum {
public:
    TrieNode *root;
    unordered_map<string, int> umap;
    MapSum() {
        root = new TrieNode();    
    }
    
    void insert(string key, int val) {
        int diff = val - umap[key];
        TrieNode* curr = root;
        for(int i = 0; i<key.size(); i++){
            int k = key[i] - 'a';
            if(curr -> children[k] == NULL){
                curr -> children[k] = new TrieNode();
            }
            curr = curr -> children[k];
            curr -> value += diff;
        }
        umap[key] = val;
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        for(int i = 0; i<prefix.size(); i++){
            int k = prefix[i] - 'a';
            if(curr -> children[k] == NULL) return 0;
            curr = curr -> children[k];
        }
        return curr -> value;
    }
};
