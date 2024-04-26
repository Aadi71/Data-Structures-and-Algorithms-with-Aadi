// https://leetcode.com/problems/minimum-falling-path-sum/

// Tabulation
class Solution {
public:
    int solve(int n, int i, int j, vector<vector<int>>& matrix) {
        if (i == n) return 0;
        int a = INT_MAX, c = INT_MAX, b;
        if (j - 1 >= 0) a = solve(n, i + 1, j - 1, matrix);
        b = solve(n, i + 1, j, matrix);
        if (j + 1 < n) c = solve(n, i + 1, j + 1, matrix);
        return matrix[i][j] + min(a, min(b, c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(n, 0, j, matrix));
        }
        return ans;
    }
};

// DP + Memoization with SC: O(n X n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 101));
        for(int j = 0; j<n; j++) dp[n - 1][j] = matrix[n - 1][j];
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int l, d, r;
                if(j - 1 < 0) l = INT_MAX;
                else l = matrix[i][j] + dp[i + 1][j - 1];
                if(j + 1 >= n) r = INT_MAX;
                else r = matrix[i][j] + dp[i + 1][j + 1];
                d = matrix[i][j] + dp[i + 1][j];
                dp[i][j] = min(l, min(d, r));
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) ans = min(ans, dp[0][i]);
        return ans;
    }
};

// Space Optimized, without any extra space O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int a = INT_MAX, c = INT_MAX, b;
                if (j - 1 >= 0) a = matrix[i + 1][j - 1];
                b = matrix[i + 1][j];
                if (j + 1 < n) c = matrix[i + 1][j + 1];
                matrix[i][j] = matrix[i][j] + min(a, min(b, c));
            }
        }
        for(int j = 0; j < n; j++) {
            ans = min(ans, matrix[0][j]);
        }
        return ans;
    }
};
