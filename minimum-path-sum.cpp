// https://leetcode.com/problems/minimum-path-sum/

// Recursive Solution - Giving TLE as time complexity is exponential. TC - O(2 ^ (m X n))
class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& grid) {
        if (i == (m-1) && j == (n-1)) {
            return grid[m - 1][n - 1];
        }
        else if (i >= m || j >= n) return INT_MAX;
        return grid[i][j] + min(solve(m, n, i + 1, j, grid), solve(m, n, i, j + 1, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        return solve(grid.size(), grid[0].size(), 0, 0, grid);
    }
};

// Memoization - Not Accpeted, giving TLE.
class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if (i == (m-1) && j == (n-1)) {
            return grid[m - 1][n - 1];
        }
        else if (i >= m || j >= n) return INT_MAX;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(m, n, i + 1, j, grid, dp), solve(m, n, i, j + 1, grid, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp (m, vector<int> (n, -1));
        return solve(m, n, 0, 0, grid, dp);
    }
};

// Tabulation and Memoization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int d = INT_MAX;
                int r = INT_MAX;
                if (i + 1 < m) d = grid[i][j] + dp[i + 1][j];
                if (j + 1 < n) r = grid[i][j] + dp[i][j + 1];
                if(i == m - 1 && j == n - 1) dp[i][j] = grid[i][j];
                else dp[i][j] = min(d, r);
            }
        }
        return dp[0][0];
    }
};


// Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int d = INT_MAX;
                int r = INT_MAX;
                if (i + 1 < m) d = grid[i][j] + prev[j];
                if (j + 1 < n) r = grid[i][j] + curr[j + 1];
                if(i == m - 1 && j == n - 1) curr[j] = grid[i][j];
                else curr[j] = min(d, r);
            }
            prev = curr;
        }
        return curr[0];
    }
};
