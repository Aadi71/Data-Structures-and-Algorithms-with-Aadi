// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int solve(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        int left = max(0, solve(root -> left, ans));
        int right = max(0, solve(root -> right, ans));
        ans = max(ans, left + right + root -> val);
        return max(left, right) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};
