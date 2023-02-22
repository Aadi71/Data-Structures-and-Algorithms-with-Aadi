// https://leetcode.com/problems/balanced-binary-tree/

// Brute Force, checking difference in heights for both left and right for each and every node.
// T.C: O(N^2)
class Solution {
public:
    int depth(TreeNode *node){
        if(node == NULL) return 0;
        return max(depth(node -> left), depth(node -> right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lHeight = depth(root -> left);
        int rHeight = depth(root -> right);
        return (abs(lHeight - rHeight) <= 1 && isBalanced(root -> left) && isBalanced(root -> right));
    }
};

//  Optimized Approach with TC: O(N)
class Solution {
public:
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int left = solve(root -> left);
        if(left == - 1) return -1;
        int right = solve(root -> right);
        if(right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};
