// https://leetcode.com/problems/number-of-ways-to-split-array/description/

// Brute Force O(N) Solution
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int totalSplits = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        long long currentSum = 0;
        for(int i = 0; i < n - 1; i++) {
            currentSum += nums[i];
            if (currentSum >= (sum - currentSum)) totalSplits++;
        }
        return totalSplits;
    }
};



