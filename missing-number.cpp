// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // Solution 1
        int n = nums.size();
        
        int m = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i<n; i++){
            m = max(m, nums[i]);
            sum += nums[i];
        }
        if(m+1 == nums.size()) return m+1; 
        return ((m * (m+1) / 2) - sum);
        
        
        // Solution 2:
        int m = *max_element(nums.begin(), nums.end());
        if(m != nums.size()) return nums.size();
        vector<int> arr(m+1, 0);
        for (int i = 0; i < nums.size(); i++)
            arr[nums[i]] = 1;
        for (int i = 0; i < m + 1; i++)
            if (arr[i] == 0)
                return i;
        return -1;
        
        // Solution 3
        int n = nums.size();
        int sum = (n * (n+1)) / 2;
        int check = 0;
        for(int i = 0; i<n; i++) check += nums[i];
        return sum - check;
    }
};
