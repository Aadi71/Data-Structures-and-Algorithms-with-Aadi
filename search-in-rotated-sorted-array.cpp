// https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        
        // If last element is smaller than target than the target element will be from 0 index
        // If last element is bigger than target will be in between 
        
        while(min < max){
            int mid = (min + max) / 2;
            
            if(nums[mid] > nums[max]) min = mid + 1;
            else max = mid;
        }
        
        if(nums[nums.size() - 1] < target){
            max = min - 1;
            min = 0;
        }
        else{
            max = nums.size() - 1;
        }
        cout<<min<<" "<<max;
        while(min <= max){
            
            int mid = (min + max) / 2;
            
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) max = mid - 1;
            else min = mid + 1;
        }
        return -1;
    }
};
