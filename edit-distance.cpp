// https://leetcode.com/problems/edit-distance/

// Recursive Solution
class Solution {
public:
    int solve(int i, string word1, int j, string word2){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(word1[i] == word2[j]) return solve(i - 1, word1, j - 1, word2);
        int ins = 1 + solve(i, word1, j - 1, word2);
        int del = 1 + solve(i - 1, word1, j, word2);
        int rep = 1 + solve(i - 1, word1, j - 1, word2);
        return min({ins, del, rep});
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        return solve(len1 - 1, word1, len2 - 1, word2);
    }
};


// Memoization
class Solution {
public:
    int solve(int i, string word1, int j, string word2, vector<vector<int>> &dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return solve(i - 1, word1, j - 1, word2, dp);
        int ins = 1 + solve(i, word1, j - 1, word2, dp);
        int del = 1 + solve(i - 1, word1, j, word2, dp);
        int rep = 1 + solve(i - 1, word1, j - 1, word2, dp);
        return dp[i][j] = min({ins, del, rep});
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return solve(len1 - 1, word1, len2 - 1, word2, dp);
    }
};


// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        for(int i = 0; i <= len1; i++) dp[i][0] = i;
        for(int j = 0; j <= len2; j++) dp[0][j] = j;
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        }
        return dp[len1][len2];
    }
};

// Space Optimiaation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<int> curr(len2 + 1, 0), prev(len2 + 1, 0);
        for(int j = 0; j <= len2; j++) prev[j] = j;
        for(int i = 1; i <= len1; i++){
            curr[0] = i;
            for(int j = 1; j <= len2; j++){
                if(word1[i - 1] == word2[j - 1]) curr[j] = prev[j - 1];
                else curr[j] = 1 + min({prev[j - 1], prev[j], curr[j - 1]});
            }
            prev = curr;
        }
        return prev[len2];
    }
};
