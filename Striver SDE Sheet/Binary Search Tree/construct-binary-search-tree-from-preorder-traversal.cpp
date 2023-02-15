// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

class Solution {
public:
    TreeNode* insert(TreeNode* node, int val){
        if(node == NULL) return new TreeNode(val);
        if(val > node -> val) node -> right = insert(node -> right, val);
        else node -> left = insert(node -> left, val);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 1;
        while(i < preorder.size()){
            insert(root, preorder[i]);
            i++;
        }
        return root;
    }
};
