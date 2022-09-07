// https://leetcode.com/problems/house-robber/

#define fr(a,b) for(int i = a; i < b; i++)

class Solution {
public:
    int rob(vector<int>& nums) {
        int incl = nums[0];
        int excl = 0;
        int excl_new;
        fr(1, nums.size()){
            excl_new = max(excl, incl);
            incl = excl + nums[i];
            excl = excl_new;
        }
        return max(incl, excl);
    }
};
