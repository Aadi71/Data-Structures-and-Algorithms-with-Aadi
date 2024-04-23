// https://leetcode.com/problems/longest-common-subsequence/

// Recursive, Giving TLE
class Solution {
public:
    int solve(string text1, string text2, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (text1[i] == text2[j]) return 1 + solve(text1, text2, i + 1, j + 1);
        return max(solve(text1, text2, i + 1, j), solve(text1, text2, i, j + 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0, 0);
    }
};

// Memoization
class Solution {
public:
    int solve(string text1, string text2, int i, int j, vector<vector<int>> &dp) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (text1[i] == text2[j]) return 1 + solve(text1, text2, i + 1, j + 1, dp);
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.size(), vector<int> (text2.size(), -1));
        return solve(text1, text2, 0, 0, dp);
    }
};

// Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.size() + 1, vector<int> (text2.size() + 1, 0));
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

// Space Optimized
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> curr(text2.size() + 1, 0);
        vector<int> prev(text2.size() + 1, 0);
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return curr[text2.size()];
    }
};
