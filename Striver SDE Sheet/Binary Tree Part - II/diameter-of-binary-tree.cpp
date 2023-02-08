// https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int height(TreeNode* root, int &d){
        if(!root) return 0;
        int l = height(root -> left, d);
        int r = height(root -> right, d);  
        d = max(d, l + r);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int d = 0;
        height(root, d);
        return d;
    }
};
