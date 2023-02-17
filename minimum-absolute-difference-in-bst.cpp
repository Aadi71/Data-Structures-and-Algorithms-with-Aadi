// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

class Solution {
public:
    int mini = INT_MAX;
    int prev = INT_MAX;
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root -> left);
        mini = min(mini, abs(prev - root -> val));
        prev = root -> val;
        inOrder(root -> right);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inOrder(root);
        return mini;
    }
};
