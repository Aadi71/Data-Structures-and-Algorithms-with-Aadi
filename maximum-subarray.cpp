// https://leetcode.com/problems/maximum-subarray/submissions/
// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i< nums.size(); i++){
            if(sum < 0) sum =0;
            sum += nums[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};

// DP Approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            nums[i] = nums[i] + (nums[i-1] > 0 ? nums[i - 1] : 0);
            sum = max(sum, nums[i]);
        }
        return sum;
    }
};
