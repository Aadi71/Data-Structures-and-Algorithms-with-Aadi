// https://leetcode.com/problems/house-robber/

// Brute Force, pick/not-pick concept. TC: 2^n
class Solution {
public:
    int solve(int ind, vector<int>& nums) {
        if (ind >= nums.size()) return 0;
        return max(nums[ind] + solve(ind + 2, nums), solve(ind + 1, nums));
    }
    int rob(vector<int>& nums) {
        return solve(0, nums);
    }
};

// Memoized
class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int> &dp) {
        if (ind >= nums.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        return dp[ind] = max(nums[ind] + solve(ind + 2, nums, dp), solve(ind + 1, nums, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            int pick = nums[i];
            if (i + 2 < n) pick += dp[i + 2];
            int notPick = INT_MIN;
            if (i + 1 < n) notPick = dp[i + 1];
            dp[i] = max(pick, notPick);
        }
        return dp[0];
    }
};


