// https://leetcode.com/problems/minimum-distance-between-bst-nodes/


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
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        inOrder(root);
        return mini;
    }
};
