// https://leetcode.com/problems/majority-element/submissions/

// Solution-1 Without using Maps
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int freq = 0;
        int max = nums[0];
        for(int i = 0; i<nums.size();i++){
            if(nums[i] == max) 
                freq++;
            else if(nums[i] != max)
                freq--;
            
            if(freq == 0){
                max = nums[i];
                freq = 1;
            }
        }
        return max;
    }
};
