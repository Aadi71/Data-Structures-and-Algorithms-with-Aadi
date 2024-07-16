// https://leetcode.com/problems/create-binary-tree-from-descriptions/description

// LCA + DFS

class Solution {
public:
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue) {
        if (root == NULL || root -> val == startValue || root -> val == destValue) return root;
        TreeNode* left = findLCA(root -> left, startValue, destValue);
        TreeNode* right = findLCA(root -> right, startValue, destValue);
        if (left == NULL) return right;
        if (right == NULL) return left;
        else return root;
    }

    bool pathToNode(TreeNode* root, int val, string &s) {
        if (root == NULL) return false;
        if (root -> val == val) return true;

        s.push_back('L');
        if (pathToNode(root -> left, val, s)) return true;
        s.pop_back();

        s.push_back('R');
        if (pathToNode(root -> right, val, s)) return true;
        s.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        string sPath;
        pathToNode(lca, startValue, sPath);
        string dPath;
        pathToNode(lca, destValue, dPath);
        return string(sPath.size(), 'U') + dPath;
    }
};
