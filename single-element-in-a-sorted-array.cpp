// https://leetcode.com/problems/single-element-in-a-sorted-array/

// Brute Force: O(N) solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i<nums.size(); i++) x ^= nums[i];
        return x;
    }
};

// Binary Search, O(logN) Solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2;
        while(low <= high){
            int mid = (high + low) / 2;
            if(nums[mid] == nums[mid ^ 1]) low = mid + 1;
            else high = mid - 1;
        }
        return nums[low];
    }
};
