// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 0; 
        int max = nums.size() - 1;
        while(min < max){
            int mid = (min + max) / 2;
            if(nums[mid] > nums[max]) min = mid + 1;
            else max = mid;
        }
        return nums[min];
    }
};
