// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

class TrieNode{
    public:
    TrieNode *children[2];
    TrieNode(){
        for(int i = 0; i < 2; i++) children[i] = NULL;
    }
};

class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode* curr = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(curr -> children[bit] == NULL) curr -> children[bit] = new TrieNode();
            curr = curr -> children[bit];
        }
    }

    int getMaxXOR(int x){
        TrieNode* curr = root;
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(curr -> children[1 - bit] != NULL){
                ans = ans | (1 << i);
                curr = curr -> children[1 - bit];
            }
            else curr = curr -> children[bit];
        }
        return ans;
    }
};

class Solution {
public:
    static bool sortCol(const vector<int> &v1, const vector<int> &v2){
        return v1[1] < v2[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie t;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<queries.size(); i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), sortCol);
        int i = 0, j = 0;
        vector<int> res(queries.size());
        while(j < queries.size()){
            while(i < nums.size() && nums[i] <= queries[j][1]) t.insert(nums[i++]);
            if(i == 0) res[queries[j][2]] = -1;
            else res[queries[j][2]] = t.getMaxXOR(queries[j][0]);
            j++;
        }
        return res;
    }
};
