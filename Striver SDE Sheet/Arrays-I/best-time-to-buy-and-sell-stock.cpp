// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        for(int i = 1; i<prices.size(); i++){
            int cost = prices[i] - mini;
            ans = max(ans, cost);
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};
