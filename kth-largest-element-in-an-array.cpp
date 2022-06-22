// https://leetcode.com/problems/kth-largest-element-in-an-array/

// QuickSelect Algorithm

class Solution {
public:
    int quickSelect(vector<int>& nums, int l, int r, int k){
        int pivot = nums[r];
        int p = l;
        
        for(int i = l; i<r; i++){
            if(nums[i] <= pivot){
                swap(nums[p], nums[i]);
                p++;
            }
        }    
        swap(nums[p], nums[r]);
        
        if(p > k) return quickSelect(nums, l, p - 1, k);
        else if(p < k) return quickSelect(nums, p + 1, r, k);
        else return nums[p];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        int answer = quickSelect(nums, 0, n-1, k);
            
        return answer;
    }
};
