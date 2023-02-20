// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(nums[i] == 0){
                ans = ans > sum ? ans : sum;
                sum = 0;
            }
        }
        ans = ans > sum ? ans : sum;
        return ans;
    }
};
