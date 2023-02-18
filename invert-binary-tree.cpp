// https://leetcode.com/problems/invert-binary-tree/

// Recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* node = root -> left;
        root -> left = invertTree(root -> right);
        root -> right = invertTree(node);
        return root;
    }
};

// Iterative BFS Solution.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            TreeNode* temp = node -> left;
            node -> left = node -> right;
            node -> right = temp;
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
        return root;
    }
};
