 // https://leetcode.com/problems/count-good-nodes-in-binary-tree/

class Solution {
public:
    void count(TreeNode* root, int m, int &res){
        if(root == NULL) return;
        if(root -> val >= m) res++;
        m = max(root -> val, m);
        count(root -> left, m, res);
        count(root -> right, m, res);
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        count(root, root -> val, res);
        return res;
    }
};
