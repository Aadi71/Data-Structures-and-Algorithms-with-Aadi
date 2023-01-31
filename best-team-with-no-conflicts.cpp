// https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> v;
        int n = scores.size();
        for(int i = 0; i<n; i++) v.push_back({ages[i], scores[i]});
        sort(v.begin(), v.end());
        vector<int> dp(n, 0);
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            dp[i] = v[i].second;
            for(int j = 0; j<i; j++){
                if(v[j].second <= v[i].second){
                    dp[i] = max(dp[i], v[i].second + dp[j]);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
