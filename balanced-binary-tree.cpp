// https://leetcode.com/problems/balanced-binary-tree/

class Solution {
public:
//     int depth(TreeNode* root){
//         if(root == NULL) return 0;
//         return max(depth(root -> left), depth(root -> right)) + 1;
//     }
        
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL) return true;
//         int left = depth(root -> left);
//         int right = depth(root -> right);
        
//         return abs(left - right) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
//     }
    int bottomUp(TreeNode* root){
        if(root == NULL) return 0;
        
        int lHeight = bottomUp(root -> left);
        if(lHeight == -1) return -1;
        
        int rHeight = bottomUp(root -> right);
        if(rHeight == -1) return -1;
        
        if(abs(rHeight - lHeight) > 1) return -1;
        return max(lHeight, rHeight) + 1;
    }
    
    
    bool isBalanced(TreeNode* root) {
        return bottomUp(root) != -1;
    }
    
};
