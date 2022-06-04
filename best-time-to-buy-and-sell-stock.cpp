// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // int start = 0;
        // int last = n - 1;
        // int profit = 0;
        // while(start < last){
        //     for(int j = start + 1; j <= last; j++){
        //         profit = max(profit, prices[j] - prices[start]);
        //     }
        //     start ++;
        // }
        // return profit 
      
      
        int profit = 0;
        int buy = prices[0];
        for(int j = 1; j<n; j++){
            profit = max(profit, prices[j] - buy);
            buy = min(buy, prices[j]);
        }
        return profit;
    }
};
