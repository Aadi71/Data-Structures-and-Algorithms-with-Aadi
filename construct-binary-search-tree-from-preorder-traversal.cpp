// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* insertBST(TreeNode* root, int val){
        if(root == NULL) return new TreeNode(val);
        if(val < root -> val) root -> left = insertBST(root -> left, val);
        else root -> right = insertBST(root -> right, val);
        return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 1;
        while(i < preorder.size()){
            insertBST(root, preorder[i]);
            i++;
        }
        return root;
    }
};
