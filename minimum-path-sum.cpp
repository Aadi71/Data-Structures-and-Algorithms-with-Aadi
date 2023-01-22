// https://leetcode.com/problems/minimum-path-sum/

// Recursive Solution - Giving TLE as time complexity is exponential. TC - O(2 ^ (m X n))
class Solution {
public:
    bool valid(int i, int j, int m, int n){
        if(i >= 0 && j >= 0 && i < m && j < n) return true;
        return false;
    }
    int solve(int i, int j, int m, int n, int sum, vector<vector<int>>& grid){
        if (valid(i, j, m, n) == false) return INT_MAX;
        sum += grid[i][j];
        if(i == m - 1 && j == n - 1) return sum;
        return min(solve(i + 1, j, m, n, sum, grid), solve(i, j + 1, m, n, sum, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(0, 0, m, n, 0, grid);
    }
};  

// Memoization - Not Accpeted, giving TLE.
class Solution {
public:
    bool valid(int i, int j, int m, int n){
        if(i >= 0 && j >= 0 && i < m && j < n) return true;
        return false;
    }
    int solve(int i, int j, int m, int n, int sum, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if (valid(i, j, m, n) == false) return INT_MAX;
        sum += grid[i][j];
        if(i == m - 1 && j == n - 1) return dp[i][j] = sum;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        return min(solve(i + 1, j, m, n, sum, grid, dp), solve(i, j + 1, m, n, sum, grid, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));
        return solve(0, 0, m, n, 0, grid, dp);
    }
};  

// Tabulation and Memoization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for(int i = m - 2; i >= 0; i--) dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
        for(int j = n - 2; j >= 0; j--) dp[m - 1][j] = grid[m - 1][j] + dp[m - 1][j + 1];
        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j>= 0; j--){
                dp[i][j] = min(grid[i][j] + dp[i + 1][j], grid[i][j] + dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};
