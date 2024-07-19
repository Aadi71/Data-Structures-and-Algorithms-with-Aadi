// https://leetcode.com/problems/delete-nodes-and-return-forest/

class Solution {
public:
    vector<TreeNode*> forest;
    TreeNode* solve(TreeNode* root, unordered_set<int> &uset){
        if (root == NULL) return nullptr;
        root -> left = solve(root -> left, uset);
        root -> right = solve(root -> right, uset);

        if (uset.find(root -> val) != uset.end()) {
            if (root -> left) forest.push_back(root -> left);
            if (root -> right) forest.push_back(root -> right);
            delete root;
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> uset;
        for(auto itr: to_delete) uset.insert(itr);
        root = solve(root, uset);
        if (root) forest.push_back(root);
        return forest;
    }
};
