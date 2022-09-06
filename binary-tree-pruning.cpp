// https://leetcode.com/problems/binary-tree-pruning/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        if(root -> left) root -> left = pruneTree(root -> left);
        if(root -> right) root -> right = pruneTree(root -> right);
        if(root -> val == 0 && !root -> left && !root -> right) return NULL;
        return root;
    }
};
