// https://leetcode.com/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos = 0, neg = 0, zero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) pos++;
            else if(nums[i] < 0) neg++;
            else zero++;
            if(zero > 0) return 0;
        }
        if(neg % 2 == 0) return 1;
        else return -1;
    }
};
