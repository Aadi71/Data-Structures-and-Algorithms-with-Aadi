// https://leetcode.com/problems/leaf-similar-trees/


class Solution {
public:
    void values(TreeNode* root, string &s){
        if(!root) return;
        if(!root -> left && !root -> right) s += to_string(root -> val)+'-';
        values(root -> left, s);
        values(root -> right, s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string c1, c2;
        values(root1, c1);
        values(root2, c2);
        return c1 == c2;
    }
};
