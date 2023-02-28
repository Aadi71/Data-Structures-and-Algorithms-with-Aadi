// https://leetcode.com/problems/longest-common-subsequence/

// Recursive, Giving TLE
class Solution {
public:
    int solve(int i, string a, int j, string b){
        if(i < 0 || j < 0) return 0;
        if(a[i] == b[j]) return 1 + solve(i - 1, a, j - 1, b);
        else return max(solve(i, a, j - 1, b), solve(i - 1, a, j, b));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
        return solve(text1.length() - 1, text1, text2.length() - 1, text2);
    }
};

// Memoization
class Solution {
public:
    int solve(int i, string a, int j, string b, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = 1 + solve(i - 1, a, j - 1, b, dp);
        else return dp[i][j] = max(solve(i, a, j - 1, b, dp), solve(i - 1, a, j, b, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
        return solve(text1.length() - 1, text1, text2.length() - 1, text2, dp);
    }
};

// Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int> (text2.length() + 1, -1));
        for(int i = 0; i <= text1.length(); i++) dp[i][0] = 0;
        for(int j = 0; j <= text2.length(); j++) dp[0][j] = 0;
        for(int i = 1; i <= text1.length(); i++){
            for(int j = 1; j <= text2.length(); j++){
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.length()][text2.length()];
    } 
};

// Space Optimized
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.length() + 1, 0), curr(text2.length() + 1, 0);
        for(int i = 1; i <= text1.length(); i++){
            for(int j = 1; j <= text2.length(); j++){
                if(text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[text2.length()];
    } 
};

