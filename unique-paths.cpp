// https://leetcode.com/problems/unique-paths/

// Recursive Solution - Giving TLE. TC - O(2^(n X m))
class Solution {
public:
    int solve(int m, int n, int i, int j) {
        if (i == (m - 1) && j == (n - 1)) return 1;
        else if (i >= m || j >= n) return 0;
        else return solve(m, n, i, j + 1) + solve(m, n, i + 1, j);
    }
    int uniquePaths(int m, int n) {
        return solve(m, n, 0, 0);
    }
};

// Memoization Solution - Accepted. TC - O(n X m) 
class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>> &dp) {
        if (i == (m - 1) && j == (n - 1)) return 1;
        else if (i >= m || j >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = solve(m, n, i, j + 1, dp) + solve(m, n, i + 1, j, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m, n, 0, 0, dp);
    }
};

// Tabulation 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[m - 1][n - 1] = 1;
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if (i + 1 < m) dp[i][j] += dp[i + 1][j];
                if (j + 1 < n) dp[i][j] += dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};


// Tabulation : Space Optimized O(N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> curr (n, 0);
        vector<int> prev (n, 0);
        curr[n - 1] = 1;
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if (i + 1 < m) curr[j] = prev[j];
                if (j + 1 < n) curr[j] += curr[j + 1];
            }
            prev = curr;
        }
        return curr[0];
    }
};
