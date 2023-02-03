// https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node != NULL){
                st.push(node -> right);
                st.push(node -> left);
                v.push_back(node -> val);
            }
        }
        return v;
    }
};
