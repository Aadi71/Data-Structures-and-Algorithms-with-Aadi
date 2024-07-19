// https://leetcode.com/problems/create-binary-tree-from-descriptions

class Solution {
public:
    TreeNode* constructTree(int val, unordered_map<int, vector<pair<int, bool>>> &child) {
        TreeNode* node = new TreeNode(val);
        if (child.find(val) != child.end()) {
            for(auto itr: child[val]) {
                if (itr.second) {
                    node -> left = constructTree(itr.first, child);
                } else {
                    node -> right = constructTree(itr.first, child);
                }
            }
        }
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_set<int> parentCount;
        unordered_set<int> childCount;
        unordered_map<int, vector<pair<int, bool>>> child;
        int rootVal = 0;
        for (int i = 0; i < d.size(); i++) {
            int a = d[i][0], b = d[i][1], c = d[i][2];
            parentCount.insert(a);
            childCount.insert(b);
            child[d[i][0]].push_back({b, c});
        }

        for(auto itr: parentCount) {
            if (!childCount.contains(itr)) {
                rootVal = itr;
                break;
            }
        }
        return constructTree(rootVal, child);
    }
};
