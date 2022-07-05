// https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    void build(vector<string>& v, TreeNode* root, string t){
        if(!root -> left && !root -> right){
            v.push_back(t);
            return;
        }
        if(root -> left) build(v, root -> left, t + "->" + to_string(root -> left -> val));
        if(root -> right) build(v, root -> right, t + "->" + to_string(root -> right -> val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root == NULL) return v;
        build(v, root, to_string(root -> val));
        return v;
    }
};
