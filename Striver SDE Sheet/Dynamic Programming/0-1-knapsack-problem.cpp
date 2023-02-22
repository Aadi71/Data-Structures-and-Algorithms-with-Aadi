// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// Recursive Solution. TC: O(2^n)
class Solution{
    public:
    int solve(int ind, int W, int *wt, int *val, int n){
        if(ind == n) return 0;
        int notTake = solve(ind + 1, W, wt, val, n);
        int take = INT_MIN;
        if(wt[ind] <= W) take = val[ind] + solve(ind + 1, W - wt[ind], wt, val, n);
        return max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) {
        return solve(0, W, wt, val, n);
    }
};

// Memoization DP. TC: (n X w) Also this contain Auxiliary Stack space due to recursion
class Solution{
    public:
    int solve(int ind, int W, int *wt, int *val, int n, vector<vector<int>> &dp){
        if(ind == n) return 0;
        if(dp[ind][W] != -1) return dp[ind][W];
        int notTake = solve(ind + 1, W, wt, val, n, dp);
        int take = INT_MIN;
        if(wt[ind] <= W) take = val[ind] + solve(ind + 1, W - wt[ind], wt, val, n, dp);
        return dp[ind][W] = max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int> (W + 1, -1));
        return solve(0, W, wt, val, n, dp);
    }
};

// Tabulation code. TC: O(n X W)
lass Solution{
    public:
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int> (W + 1, 0));
        for(int i = wt[0]; i <= W; i++) dp[0][i] = val[0];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= W; j++){
                int notTake = dp[i - 1][j];
                int take = INT_MIN;
                if(wt[i] <= j) take = val[i] + dp[i - 1][j - wt[i]];
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};

// Space Optimized to 1-D two (prev and curr) arrays
class Solution{
    public:
    int knapSack(int W, int wt[], int val[], int n) {
        vector<int> prev(W + 1, 0), curr(W + 1, 0);
        for(int i = wt[0]; i <= W; i++) prev[i] = val[0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= W; j++){
                int notTake = prev[j];
                int take = INT_MIN;
                if(wt[i] <= j) take = val[i] + prev[j - wt[i]];
                curr[j] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};

// Best Space Optimized to single 1-D array
class Solution{
    public:
    int knapSack(int W, int wt[], int val[], int n) {
        vector<int> curr(W + 1, 0);
        for(int i = wt[0]; i <= W; i++) curr[i] = val[0];
        for(int i = 1; i < n; i++){
            for(int j = W; j >= 0; j--){
                int notTake = curr[j];
                int take = INT_MIN;
                if(wt[i] <= j) take = val[i] + curr[j - wt[i]];
                curr[j] = max(take, notTake);
            }
        }
        return curr[W];
    }
};
