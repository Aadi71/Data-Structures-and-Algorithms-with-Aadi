// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        int maximum = *max_element(nums.begin(), nums.end());
        
        int mini = 1;
        int maxi = 1;
        
        for(int i = 0; i<nums.size(); i++){
            int temp = maxi * nums[i];
            maxi = max(nums[i] * maxi, max(nums[i], nums[i] * mini));
            mini = min(temp, min(nums[i], nums[i] * mini));
            maximum = max(maximum, maxi);
        }
        
        return maximum;
        
    }
};
