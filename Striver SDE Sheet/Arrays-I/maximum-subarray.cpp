// https://leetcode.com/problems/maximum-subarray/

// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int temp = 0;
        for(int i = 0; i<nums.size(); i++){
            temp += nums[i];
            ans = max(ans, temp);
            if(temp < 0) temp = 0;
        }
        return ans;
    }
};

// Using Dynamic Approach
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
