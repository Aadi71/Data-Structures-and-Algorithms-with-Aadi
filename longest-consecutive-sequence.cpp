// https://leetcode.com/problems/longest-consecutive-sequence/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int m = 0;
        if(nums.size() == 0) return 0;
        int temp = 1;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] == 1) temp ++;
            else{
                m = max(m, temp);
                temp = 1;
            }
        }
        m = max(m, temp);
        return m;
    }
};
