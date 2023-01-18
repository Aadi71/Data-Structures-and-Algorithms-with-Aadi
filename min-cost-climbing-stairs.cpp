// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 2) return min(cost[0], cost[1]);
        int a = cost[0], b = cost[1], c;
        for(int i = 2; i<n; i++){
            c = cost[i] + min(a, b);
            a = b;
            b = c;
        }
        return min(a, b);
    }
};
