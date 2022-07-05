// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root -> right, p, q);
        else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root -> left, p, q);
        else return root;
    }
};
