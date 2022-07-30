// https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool valid(TreeNode* node, long min, long max){
        if(!node) return true;
        if (node -> val < max && node -> val > min)            
            return valid(node -> left, min, node -> val) && valid(node -> right, node -> val, max);
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};
