// https://leetcode.com/problems/minimum-jumps-to-reach-home/

class Solution {
public:
    int dp[6001][2];
    unordered_map<int, int> umap;
    int solve(int i, int j, int a, int b, int x){
        if(i == x) return 0;
        if(i < 0 || i > 6000 || umap.find(i) != umap.end()) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1 + solve(i + a, 0, a, b, x);
        if(!j) dp[i][j] = min(dp[i][j], 1 + solve(i - b, 1, a, b, x));
        return dp[i][j];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(int i = 0; i<forbidden.size(); i++) umap[forbidden[i]] = 1;;
        memset(dp,-1,sizeof(dp));
        int ans = solve(0, 0, a, b, x);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
