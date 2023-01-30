// https://leetcode.com/problems/partition-equal-subset-sum/
 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) sum += nums[i];
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> prev(target + 1, false), curr(target + 1, false);
        prev[0] = curr[0] = 1;
        if(nums[0] <= target) prev[nums[0]] = 1;
        for(int i = 1; i<n; i++){
            for(int j = 1; j<=target; j++){
                bool notTake = prev[j];
                bool take = false;
                if(nums[i] <= j) take = prev[j - nums[i]];
                curr[j] = take | notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};
