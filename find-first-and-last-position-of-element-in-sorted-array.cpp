// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


class Solution {
private:
    int first(vector <int> nums, int target){
        int n = nums.size();
        int low = 0; int high = n - 1; int res = -1;
        
        while(low<=high){
            int mid = (low+high) / 2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else{
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
    
    int last(vector <int> nums, int target){
        int n = nums.size();
        int low = 0; int high = n - 1; int res = -1;
        
        while(low<=high){
            int mid = (low+high) / 2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else{
                res = mid;
                low = mid + 1;
            }
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> final;
        
        final.push_back(first(nums, target));
        final.push_back(last(nums, target));
        return final;
    }
};
