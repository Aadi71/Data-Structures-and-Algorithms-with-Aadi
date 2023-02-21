// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class TrieNode{
    public:
    TrieNode *children[2];
    TrieNode(){ 
        for(int i = 0; i<2; i++) children[i] = NULL;
    }
};

class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode *curr = root;
        for(int i = 31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(curr -> children[bit] == NULL) curr -> children[bit] = new TrieNode();
            curr = curr -> children[bit];
        }
    }
    int getMaxXOR(int num){
        TrieNode *curr = root;
        int res = 0;
        for(int i = 31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(curr -> children[1- bit] != NULL){
                res = res | (1 << i);
                curr = curr -> children[1 - bit];
            }
            else curr = curr -> children[bit];
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int ans = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            t.insert(nums[i]);
        }
        for(int i = 0; i<nums.size(); i++){
            ans = max(ans, t.getMaxXOR(nums[i]));
        }
        return ans;
    }
};
