// https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
    int total(TreeNode* root, int low, int high, int &sum){
        if(root == NULL) return 0;
        if(root -> val >= low && root -> val <= high) sum += root -> val;
        if(root -> val < low && root -> val > high) return 0;
        total(root -> left, low, high, sum);
        total(root -> right, low, high, sum);
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        return total(root, low, high, sum);
    }
};
