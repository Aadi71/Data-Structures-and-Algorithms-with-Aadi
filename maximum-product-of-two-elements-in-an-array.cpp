//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/


// Solved by finding the biggest and second biggest element in an array 


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0;
        int b = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > a) b = exchange(a, nums[i]);
            else b = max(b, nums[i]);
        }
        return --a * --b;
    }
};
