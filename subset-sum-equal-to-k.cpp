// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?

// Recursion: Not Accepted, giving TLE
bool solve(int ind, int k, vector<int> &arr){
    if(k == 0) return true;
    if(ind == 0) return (arr[ind] == k);
    bool notTake = solve(ind - 1, k, arr);
    bool take = false;
    if(arr[ind] <= k) take = solve(ind - 1, k - arr[ind], arr);
    return take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(n - 1, k, arr);
}

// Memoization
bool solve(int ind, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0) return true;
    if(ind == 0) return (arr[ind] == k);
    if(dp[ind][k] != -1) return dp[ind][k];
    bool notTake = solve(ind - 1, k, arr, dp);
    bool take = false;
    if(arr[ind] <= k) take = solve(ind - 1, k - arr[ind], arr, dp);
    return dp[ind][k] = take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k + 1, -1));
    return solve(n - 1, k, arr, dp);
}

// Applying Dynamic Programming and implementing using matrix
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k + 1, 0));
    for(int i = 0; i<n; i++) dp[i][0] = 1;
    dp[0][arr[0]] = 1;
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=k; j++){
            bool notTake = dp[i - 1][j];
            bool take = false;
            if(arr[i] <= j) take = dp[i - 1][j - arr[i]];
            dp[i][j] = take | notTake;
        }
    }
    return dp[n - 1][k];
}

