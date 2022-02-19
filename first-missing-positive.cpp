// https://leetcode.com/problems/first-missing-positive/submissions/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        
        int a = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<size; i++){
            if(nums[i] > a)
                break;
            else if(nums[i] == a) a++;
        }
        return a;
        
    }
};
