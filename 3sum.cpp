// https://leetcode.com/problems/3sum/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        if(nums.size()<3) return v;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++) cout<<nums[i]<<" ";
        int i = 0;
        int j = i + 1;
        int k = nums.size() - 1;
        while(i < nums.size() - 2){
            
            while(j<k && (i==0 || nums[i]!=nums[i-1])){
                if(nums[i] + nums[j] + nums[k] == 0){
                    v.push_back({nums[i],nums[j],nums[k]});
                    j++; 
                    while(nums[j] == nums[j - 1] && j<k) j++;
                }
                else if(nums[i] + nums[j] + nums[k] > 0) k--;
                else j++;
            }
            i++;
            j = i + 1;
            k = nums.size() - 1;
        }
        return v;
    }
};
