// https://leetcode.com/problems/sum-of-left-leaves/

class Solution {
public:
    int sum = 0;
    int calc(TreeNode* root){
        if(root == NULL) return sum;
        if(root->left && !root->left->left && !root->left->right) sum += root->left-> val;
        if(root -> left) calc(root -> left);
        if(root -> right) calc(root -> right);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum = calc(root);
        return sum;
    }
};
