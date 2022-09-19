// https://leetcode.com/problems/maximum-number-of-pairs-in-array/

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(2, 0);
        unordered_map<int, int> umap;
        
        for(auto x: nums){
            umap[x]++;
        }
        
        for(auto x: umap){
            v[0] += x.second / 2;
            v[1] += x.second % 2;
        }
        return v;
    }
};
