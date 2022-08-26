// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;   
        for(int i = 0; i<=nums.size()-k; i++){
            result = min(result, nums[i+k-1] - nums[i]);
        }
        return result;
    }
};
