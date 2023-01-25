// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mini = 0, maxi = 0;
        while(maxi < n - 1){
            int far = 0;
            for(int i = mini; i<=maxi; i++) far = max(far, i + nums[i]);
            mini = maxi + 1;
            maxi = far;
            ans++;
        }
        return ans;
    }
};
