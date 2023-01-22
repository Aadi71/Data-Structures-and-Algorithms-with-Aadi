// https://leetcode.com/problems/unique-paths-ii/

// For better understanding of this type of question, and how we reached to this solution please visit: https://leetcode.com/problems/unique-paths/solutions/3085132/recursion-memoization-tabulation/

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid){
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j]; 
        return dp[i][j] = (solve(i + 1, j, m, n, dp, obstacleGrid) + solve(i, j + 1, m, n, dp, obstacleGrid));
    } 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(0, 0, m, n, dp, obstacleGrid);
    }
};
