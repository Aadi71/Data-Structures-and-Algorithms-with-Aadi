// https://leetcode.com/problems/univalued-binary-tree/

class Solution {
public:
    bool check(TreeNode* root, int val){
        if(root == NULL) return true;
        if(root -> val != val) return false;
        return check(root->left, val) && check(root->right, val);
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return root;
        int val = root -> val;
        return check(root, val);
    }
};
