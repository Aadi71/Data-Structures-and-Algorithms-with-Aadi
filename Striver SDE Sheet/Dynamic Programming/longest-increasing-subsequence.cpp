// https://leetcode.com/problems/longest-increasing-subsequence/

// Recursive
class Solution {
public:
    int solve(int prev, int ind, vector<int> &nums){
        if(ind == nums.size()) return 0;
        int len = solve(prev, ind + 1, nums);
        if(prev == - 1 || nums[ind] > nums[prev]) len = max(len, 1 + solve(ind, ind + 1, nums));
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(-1, 0, nums);
    }
};
 
 
// Memoization
class Solution {
public:
    int solve(int prev, int ind, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        int len = solve(prev, ind + 1, nums, dp);
        if(prev == - 1 || nums[ind] > nums[prev]) len = max(len, 1 + solve(ind, ind + 1, nums, dp));
        return dp[ind][prev + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size() + 1, -1));
        return solve(-1, 0, nums, dp);
    }
};

// Tabulation


// Best Optimiezed Solution using Binary Search. TC: O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > temp[len - 1]){
                temp.push_back(nums[i]);
                len++;    
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};
