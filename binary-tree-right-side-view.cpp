// https://leetcode.com/problems/binary-tree-right-side-view/

// Recursive Traversal - Root, right, left
class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* node, int level){
        if(!node) return;
        if(level == ans.size()) ans.push_back(node -> val);
        if(node -> right) solve(node -> right, level + 1);
        if(node -> left) solve(node -> left, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};

// Iterative Traversal - Level Order
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> v;
        if (root == NULL)
        return v;
 
    queue<TreeNode*> q;
    q.push(root);
 
    while (!q.empty()) {
        // get number of nodes for each level
        int n = q.size();
 
        // traverse all the nodes of the current level
        while (n--) {
 
            TreeNode* x = q.front();
            q.pop();
 
            // print the last node of each level
            if (n == 0) {
                v.push_back(x -> val);
            }
            // if left child is not null push it into the
            // queue
            if (x->left)
                q.push(x->left);
            // if right child is not null push it into the
            // queue
            if (x->right)
                q.push(x->right);
        }  
    }
        return v;
    }
};
