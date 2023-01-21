https://leetcode.com/problems/jump-game/

// Recursive Approach - Gives TLE
class Solution {
public:
    void solve(vector<int> &nums, int ind, bool &flag){
        if(ind == nums.size() - 1){
            flag = true;
            return;
        }
        if(ind >= nums.size()) return;
        if(nums[ind] == 0) return;
        for(int i = ind + 1; i<= ind + nums[ind]; i++) solve(nums, i, flag);
    }
    bool canJump(vector<int>& nums) {
        bool flag = false;
        solve(nums, 0, flag);
        return flag;
    }
};

// Memoization - Accepted but not a good solution as T.C is O(n^2) and it is also using stack space.
class Solution {
public:
    int solve(vector<int> &nums, int ind, vector<int> &dp){
        if(ind == nums.size() - 1) return true;
        if(dp[ind] == 0) return false;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind + 1; i<= ind + nums[ind]; i++){
            if(i < nums.size() && solve(nums, i, dp)) return dp[i] = true;
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, dp);
    }
};

// Memoization - Accepted, good solution as it is not using stack space, but still its T.C is O(n^2).
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 1;
        for(int i = n - 2; i>=0; i--){
            if(nums[i] == 0){
                dp[i] = 0;
                continue;
            }
            for(int j = i + 1; j <= i + nums[i]; j++){
                if(j < n && dp[j]){
                    dp[i] = 1;
                    break;
                }
            }
            if(dp[i] == -1) dp[i] = 0;
        }
        return dp[0];
    }
};

//  Greedy Approach - with O(n) time complexity
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;
        for(int i = n - 2; i >= 0; i--) if(goal <= i + nums[i]) goal = i;
        if(goal == 0) return true;
        return false;
    }
};
