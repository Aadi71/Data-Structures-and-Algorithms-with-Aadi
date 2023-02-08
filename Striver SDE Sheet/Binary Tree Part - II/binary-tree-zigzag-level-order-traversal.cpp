// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        int order = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n--){
                TreeNode* f = q.front();
                q.pop();
                temp.push_back(f -> val);
                if(f -> left) q.push(f -> left);
                if(f -> right) q.push(f -> right);
            }
            if(order == -1) reverse(temp.begin(), temp.end());
            order *= -1;
            v.push_back(temp);
        }
        return v;
    }
};
