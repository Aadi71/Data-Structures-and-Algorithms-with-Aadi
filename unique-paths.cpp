// https://leetcode.com/problems/unique-paths/

// Recursive Solution - Giving TLE. TC - O(2^(n X m))
class Solution {
public:
    bool valid(int i, int j, int m, int n){
        if(m >= 0 && n >= 0 && i<m && j <n) return true;
        return false;
    }
    void solve(int i, int j, int m, int n, int &sum){
        if(i == m - 1 && j == n - 1){
            sum++;
            return;
        }
        if(valid(i + 1, j, m, n)) solve(i + 1, j, m, n, sum);
        if(valid(i, j + 1, m, n)) solve(i, j + 1, m, n, sum);
    }
    int uniquePaths(int m, int n) {
        int sum = 0;
        solve(0, 0, m, n, sum);
        return sum;
    }
};

// Memoization Solution - Accepted. TC - O(n X m) 
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == m - 1 && j == n - 1) return 1;
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 
        return dp[i][j] = (solve(i + 1, j, m, n, dp) + solve(i, j + 1, m, n, dp));
    } 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(0, 0, m, n, dp);
    }
};

// Tabulation 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        dp[m - 1][n - 1] = 1;
        for(int i = 0; i<m; i++) dp[i][n - 1] = 1;
        for(int j = 0; j<n; j++) dp[m - 1][j] = 1;
        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j>= 0; j--){
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};
