// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> v;
        int l = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            vector<int> temp(s);
            for(int i = 0; i<s; i++){
                TreeNode* node = q.front();
                q.pop();
                if(l == 0) temp[i] = node -> val;
                else temp[s - i - 1] = node -> val;
            
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);    
            }
            v.push_back(temp);
            l = !l;
        }
        return v;
    }
};
