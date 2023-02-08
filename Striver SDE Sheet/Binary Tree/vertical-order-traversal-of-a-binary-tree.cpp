// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {{}};
        // Node, vertical, level
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> m;
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            TreeNode* node = f.first;
            int y = f.second.first, x = f.second.second;
            m[y][x].insert(node -> val);
            if(node -> left) q.push({node -> left, {y - 1, x + 1}});
            if(node -> right) q.push({node -> right, {y + 1, x + 1}});
        }
        vector<vector<int>> ans;
        for(auto i: m){
            vector<int> temp;
            for(auto j: i.second){
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
