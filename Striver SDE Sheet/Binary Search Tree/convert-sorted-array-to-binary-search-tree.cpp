// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:
    TreeNode* solve(int min, int max, vector<int> &nums){
        if(min > max) return NULL;
        int mid = (min + max) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = solve(min, mid - 1, nums);
        root -> right = solve(mid + 1, max, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums);
    }
};
