// https://leetcode.com/problems/increasing-order-search-tree/

class Solution {
public:
    TreeNode* main = new TreeNode(0);
    TreeNode* temp = main;
    void fill(TreeNode* root){
        if(root == NULL) return;
        fill(root -> left);
        main -> right = new TreeNode(root -> val);
        main -> left = NULL;
        main = main -> right;
        fill(root -> right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL) return NULL;
        fill(root);
        return temp -> right;
    }
};
