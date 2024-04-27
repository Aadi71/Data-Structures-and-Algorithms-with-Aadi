// https://leetcode.com/problems/perfect-squares/description

// Brute Force using recursion
class Solution {
public:
    int solve(vector<int> &squares, int i, int n) {
        if (n == 0) return 0;
        if (i >= squares.size()) return 1001;
        if (n < 0) return 1001;
        int pick = 1001, notPick = 1001;
        if (squares[i] <= n) pick = 1 + solve(squares, i, n - squares[i]);
        notPick = solve(squares, i + 1, n);
        return min(pick, notPick);
    }
    int numSquares(int n) {
        vector<int> squares;
        int i = 1;
        while(i * i <= n) {
            squares.push_back(i * i);
            i++;
        }
        return solve(squares, 0, n);
    }
};

// Memoization 
class Solution {
public:
    int solve(vector<int> &squares, int i, int n, vector<vector<int>> &dp) {
        if (n == 0) return 0;
        if (i >= squares.size()) return 1001;
        if (n < 0) return 1001;
        if (dp[n][i] != -1) return dp[n][i];
        int pick = 1001, notPick = 1001;
        if (squares[i] <= n) pick = 1 + solve(squares, i, n - squares[i], dp);
        notPick = solve(squares, i + 1, n, dp);
        return dp[n][i] = min(pick, notPick);
    }
    int numSquares(int n) {
        vector<int> squares;
        int i = 1;
        while(i * i <= n) {
            squares.push_back(i * i);
            i++;
        }
        vector<vector<int>> dp(n + 1, vector<int> (squares.size(), -1));
        return solve(squares, 0, n, dp);
    }
};

