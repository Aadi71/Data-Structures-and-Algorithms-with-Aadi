// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return make(preorder, inorder, index, 0, inorder.size() - 1);
    }
    TreeNode* make(vector<int>& preorder, vector<int>& inorder, int& index, int left, int right){
        if(left > right) return NULL;
        int pivot = left;
        while(inorder[pivot] != preorder[index]) pivot++;
        index++;
        TreeNode* root = new TreeNode(inorder[pivot]);
        root -> left = make(preorder, inorder, index, left, pivot - 1);
        root -> right = make(preorder, inorder, index, pivot + 1, right);
        return root;
    }
};
