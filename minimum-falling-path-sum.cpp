// https://leetcode.com/problems/minimum-falling-path-sum/

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

// Space Optimized with SC: O(n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 101);
        vector<int> prev(n, 101);
        for(int j = 0; j<n; j++) prev[j] = matrix[n - 1][j];
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int l, d, r;
                if(j - 1 >= 0) l = matrix[i][j] + prev[j - 1];
                else l = INT_MAX;
                if(j + 1 < n) r = matrix[i][j] + prev[j + 1];
                else r = INT_MAX;
                d = matrix[i][j] + prev[j];
                dp[j] = min(l, min(d, r));
            }
            prev = dp;
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) ans = min(ans, prev[i]);
        return ans;
    }
};
