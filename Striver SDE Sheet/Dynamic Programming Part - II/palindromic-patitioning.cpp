// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

// Recursive Solution
class Solution{
public:
    bool isPalindromie(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int solve(int i, string str){
        if(i == str.length()) return 0;
        int minCost = INT_MAX;
        for(int j = i; j < str.length(); j++){
            if(isPalindromie(i, j, str)){
                int cost = 1 + solve(j + 1, str);
                minCost = min(cost, minCost);
            }
        }
        return minCost;
    }
    int palindromicPartition(string str){
        return solve(0, str) - 1;
    }
};

// Memoization
class Solution{
public:
    bool isPalindromie(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            else{i++;j--;}
        }
        return true;
    }
    int solve(int i, string str, vector<int> &dp){
        if(i == str.length()) return 0;
        if(dp[i] != - 1) return dp[i];
        int minCost = INT_MAX;
        for(int j = i; j < str.length(); j++){
            if(isPalindromie(i, j, str)){
                int cost = 1 + solve(j + 1, str, dp);
                minCost = min(cost, minCost);
            }
        }
        return dp[i] = minCost;
    }
    int palindromicPartition(string str){
        vector<int> dp(str.length(), -1);
        return solve(0, str, dp) - 1;
        
    }
};

// Tabulation
class Solution{
public:
    bool isPalindromie(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            else{i++;j--;}
        }
        return true;
    }
    int palindromicPartition(string str){
        vector<int> dp(str.length() + 1, -1);
        dp[str.length()] = 0;
        for(int i = str.length() - 1; i >= 0; i--){
            int minCost = INT_MAX;
            for(int j = i; j < str.length(); j++){
                if(isPalindromie(i, j, str)){
                    int cost = 1 + dp[j + 1];
                    minCost = min(cost, minCost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};
