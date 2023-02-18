// https://leetcode.com/problems/subsets/

// Brute Force using Power Set. TC: O(2^n X n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int n = 1 << nums.size();
        for(int i = 0; i<n; i++){
            vector<int> temp;
            for(int j = 0; j<nums.size(); j++){
                if(i & (1 << j)) temp.push_back(nums[j]);
            }
            v.push_back(temp);
        }
        return v;
    }
};

// Recursive Solution(Pick and Not Pick). TC: O(2^N)
class Solution {
public:
    void solve(vector<vector<int>> &v, vector<int> &temp, int ind, vector<int> &nums){
        if(ind == nums.size()){
            v.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(v, temp, ind+ 1, nums);
        temp.pop_back();
        solve(v, temp, ind+ 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> temp;
        solve(v, temp, 0, nums);
        return v;
    }
};
