// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Recursive Solution. Giving TLE
class Solution{
public:
    int solve(int i, int j, int arr[]){
        if(i == j) return 0;
        int mini = INT_MAX;
        for(int k = i; k < j; k++){
            int steps = (arr[i - 1] * arr[k] * arr[j]) + solve(i, k, arr) + solve(k + 1, j, arr);
            mini = min(steps, mini);
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[]){
        return solve(1, N - 1, arr);
    }
};

// Memoization
class Solution{
public:
    int solve(int i, int j, int arr[], vector<vector<int>> &dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i; k < j; k++){
            int steps = (arr[i - 1] * arr[k] * arr[j]) + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
            mini = min(steps, mini);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N, vector<int> (N, -1));
        return solve(1, N - 1, arr, dp);
    }
};

// Tabulation
class Solution{
public:
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N, vector<int> (N, -1));
        for(int i = 0; i < N; i++) dp[i][i] = 0;
        for(int i = N - 1; i >= 1; i--){
            for(int j = i + 1; j < N; j++){
                int mini = INT_MAX;
                for(int k = i; k < j; k++){
                    int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                    mini = min(steps, mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N - 1];
    }
};
