// https://leetcode.com/problems/minimum-average-difference/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) sum += nums[i];
        long long prefix = 0;
        long long minDiff = INT_MAX;
        long long diff;
        int res;
        for(int i = 0; i<n; i++) {
            prefix += nums[i];
            if(n - i - 1 == 0) diff = abs(prefix / (i + 1));
            else diff = abs((prefix / (i + 1)) - ((sum - prefix) / (n - i - 1)));
            if(diff < minDiff){
                minDiff = diff;
                res = i;
            }
        }
        return res;
    }
};
