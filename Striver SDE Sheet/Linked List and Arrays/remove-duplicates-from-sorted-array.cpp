// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// TC: O(N)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        while(j < nums.size()){
            if(nums[i] == nums[j]) j++;
            else nums[++i] = nums[j++];
        }
        return i + 1;
    }
};
