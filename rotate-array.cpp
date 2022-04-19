https://leetcode.com/problems/rotate-array/

class Solution {
public:
    
    void reverseArray(vector<int>& nums, int s, int e){
        while(s < e){
            swap(nums[s], nums[e]);
            s++; e--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverseArray(nums, 0, n-1);
        reverseArray(nums, 0, k-1);
        reverseArray(nums, k, n-1);
        
        for(int i = 0; i<n; i++) cout<<nums[i]<<" ";
    }
    
};
