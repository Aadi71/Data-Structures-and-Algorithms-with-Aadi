// https://leetcode.com/problems/diameter-of-binary-tree/
// TC: O(N^2)

class Solution {
public:
    int height(TreeNode* root, int &d){
        if(!root) return 0;
        int l = height(root -> left, d);
        int r = height(root -> right, d);  
        d = max(d, l + r);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int d = 0;
        height(root, d);
        return d;
    }
};

// Post Order Traversal (DFS Height)
class Solution {
public:
    int ans = 0;
    int dfsHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int left = dfsHeight(root -> left);
        int right = dfsHeight(root -> right);

        ans = max(ans, left + right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        dfsHeight(root);
        return ans;
    }
};
