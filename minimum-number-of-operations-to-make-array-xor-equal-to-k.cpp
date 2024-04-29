// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }
        if (result == k) return 0;
        int ans = 0;
        while(result > k ? result : k) {
            if ((1 & result) != (1 & k)) ans++;
            k >>= 1; result >>= 1;
        }
        return ans;
    }
};
