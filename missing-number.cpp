// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int m = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i<n; i++){
            m = max(m, nums[i]);
            sum += nums[i];
        }
        if(m+1 == nums.size()) return m+1; 
        return ((m * (m+1) / 2) - sum);
    }
};
