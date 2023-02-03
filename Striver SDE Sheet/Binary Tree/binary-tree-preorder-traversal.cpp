// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Implementation through Stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node != NULL){
                v.push_back(node -> val);
                st.push(node -> left);
                st.push(node -> right);
            }
        }
        return v;
    }
};

// Implementation using Recursion
class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root){
        if(root == NULL) return;
        ans.push_back(root -> val);
        solve(root -> left);
        solve(root -> right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        solve(root);
        return ans;
    }
};
