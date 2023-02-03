// https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    vector<int> v;
    void solve(TreeNode *node){
        if(node == NULL) return;
        solve(node -> left);
        v.push_back(node -> val);
        solve(node -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return v;
    }
};
