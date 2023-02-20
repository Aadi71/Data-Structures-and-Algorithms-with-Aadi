// https://leetcode.com/problems/symmetric-tree/

class Solution {
private:
    bool isEqual(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) return left == right;
        if(left -> val != right -> val) return false;
        return isEqual(left -> left, right -> right) && isEqual(left -> right, right -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isEqual(root->left, root->right);
    }  
};
