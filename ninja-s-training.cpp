// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?

// Recursive Approach
int solve(int d, int l, vector<vector<int>> &points){
    int maxi = 0;
    if(d == 0){
        for(int i = 0; i<3; i++) if(i != l) maxi = max(maxi, points[0][i]);
        return maxi;
    }
    for(int i = 0; i<3; i++){
        if(i != l){
            int point = points[d][i] + solve(d - 1, i, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points){
    return solve(n - 1, 3, points);
}

// Memoization
int solve(int d, int l, vector<vector<int>> &points, vector<vector<int>> &dp){
    int maxi = 0;
    if(d == 0){
        for(int i = 0; i<3; i++){
            if(i != l){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[d][l] != -1) return dp[d][l];
    for(int i = 0; i<3; i++){
        if(i != l){
            int point = points[d][i] + solve(d - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[d][l] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return solve(n - 1, 3, points, dp);
}
