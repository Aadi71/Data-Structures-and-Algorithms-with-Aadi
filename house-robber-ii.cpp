// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int a = 0, b = 0;
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i<n - 1; i++){
            int temp = a;
            a = max(b + nums[i], a);
            b = temp;
        }
        ans1 = a;
        a = 0, b = 0;
        for(int i = 1; i<n; i++){
            int temp = a;
            a = max(b + nums[i], a);
            b = temp;
        }
        ans2 = a;
        return max(ans1, ans2);
    }
};
