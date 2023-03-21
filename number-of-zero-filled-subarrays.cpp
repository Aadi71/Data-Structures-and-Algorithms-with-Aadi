// https://leetcode.com/problems/number-of-zero-filled-subarrays/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        int zero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) zero = 0;
            else count += ++zero;
        }
        return count;
    }
};
