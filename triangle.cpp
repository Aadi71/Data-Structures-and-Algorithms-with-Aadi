// https://leetcode.com/problems/triangle/

// Recursion Approach - Not Accepted, giving TLE
class Solution {
public:
int solve(int i, int j, vector<vector<int>>& triangle, int sum){
    if(i >= triangle.size()) return sum;
    if(j >= triangle[i].size()) return INT_MAX;
    sum += triangle[i][j];
    return min(solve(i + 1, j, triangle, sum), solve(i + 1, j + 1, triangle, sum));
}
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0, 0, triangle, 0);
    }
};

// Memoization with Recursion Approach - Accepted.
class Solution {
public:
int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp, int n){
    if(i == n - 1) return triangle[n - 1][j];
    if(dp[i][j] != INT_MAX) return dp[i][j];
    return dp[i][j] = min(triangle[i][j] + solve(i + 1, j, triangle, dp, n), triangle[i][j] + solve(i + 1, j + 1, triangle, dp, n));
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        return solve(0, 0, triangle, dp, n);
    }
};

// DP and Memoization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int j = n - 1; j >= 0; j--) dp[n - 1][j] = triangle[n - 1][j];
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                dp[i][j] = min(triangle[i][j] + dp[i + 1][j], triangle[i][j] + dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};

// Space Optimized Approach
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        for(int j = n - 1; j >= 0; j--) dp[j] = triangle[n - 1][j];
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                dp[j] = min(triangle[i][j] + dp[j], triangle[i][j] + dp[j + 1]);
            }
        }
        return dp[0];
    }
};
 
