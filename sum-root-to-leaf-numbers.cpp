// https://leetcode.com/problems/sum-root-to-leaf-numbers

class Solution {
public:
    int sum = 0;
    void rootToLeaf(TreeNode* root, int temp){
        temp = (temp * 10) + root -> val;
        if(root -> left == NULL && root -> right == NULL) {
            sum += temp;
            return;
        }
        if(root -> left) rootToLeaf(root -> left, temp);
        if(root -> right) rootToLeaf(root -> right, temp);
    }
    int sumNumbers(TreeNode* root) {
        rootToLeaf(root, 0);
        return sum;
    }
};
