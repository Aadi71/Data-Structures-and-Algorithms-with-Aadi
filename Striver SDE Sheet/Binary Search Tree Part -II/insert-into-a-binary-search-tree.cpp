// https://leetcode.com/problems/insert-into-a-binary-search-tree/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* temp = root;
        while(true){
            if(root -> val > val){
                if(root -> left == NULL){
                    root -> left = new TreeNode(val);
                    break;    
                }
                else root = root -> left;
            }
            else{
                if(root -> right == NULL){ 
                    root -> right = new TreeNode(val);
                    break;    
                }
                else root = root -> right;
            }
        }
        return temp;
    }
};
