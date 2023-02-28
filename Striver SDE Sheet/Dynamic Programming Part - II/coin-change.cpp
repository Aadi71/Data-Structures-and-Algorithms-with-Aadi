// https://leetcode.com/problems/coin-change/

// Recursive Solution, Giving TLE due to exponential time complexity
class Solution {
public:
    int solve(vector<int>& coins, int amount, int ind){
        if(ind == coins.size()) return amount == 0 ? 0 : INT_MAX - 1;
        int notTake = solve(coins, amount, ind + 1);
        int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + solve(coins, amount - coins[ind], ind);  
        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
       int res = solve(coins, amount, 0);
       if(res == INT_MAX - 1) return -1;
       return res;
    }
};

// Memoization
class Solution {
public:
    int solve(vector<int>& coins, int amount, int ind, vector<vector<int>> &dp){
        if(ind == coins.size()){
            return amount == 0 ? 0 : INT_MAX - 1;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake = solve(coins, amount, ind + 1, dp);
        int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + solve(coins, amount - coins[ind], ind, dp);  
        return dp[ind][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, -1));
       int res = solve(coins, amount, 0, dp);
       if(res == INT_MAX - 1) return -1;
       return res;
    }
};

// Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, INT_MAX - 1));
        for(int i = 0; i<=coins.size(); i++) dp[i][0] = 0;     
        for(int i = 1; i<=coins.size(); i++){
            for(int j = 1; j<=amount; j++){
                if(coins[i - 1] > j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = min(dp[i -1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
        if(dp[coins.size()][amount] == INT_MAX - 1) return -1;
        return dp[coins.size()][amount];
    }
};

// Space Optimized
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount + 1, INT_MAX - 1), curr(amount + 1, INT_MAX - 1);
        prev[0] = curr[0] = 0;
        for(int i = 1; i<=coins.size(); i++){
            for(int j = 1; j<=amount; j++){
                if(coins[i - 1] > j) curr[j] = prev[j];
                else curr[j] = min(prev[j], 1 + curr[j - coins[i - 1]]);
            }
            prev = curr;
        }
        if(prev[amount] == INT_MAX - 1) return -1;
        return prev[amount];
    }
};
