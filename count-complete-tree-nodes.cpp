// https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int ls = 1;
        TreeNode* left = root -> left;
        while(left){
            ls++;
            left = left -> left;
        }
        
        int rs = 1;
        TreeNode* right = root -> right;
        while(left){
            rs++;
            right = right -> right;
        }
        
        if(ls == rs) return pow(2, ls) - 1;
        else return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
