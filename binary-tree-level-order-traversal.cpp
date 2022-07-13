// https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector <int> temp;
        
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode * node = q.front();
                q.pop();
                temp.push_back(node->val);
                
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }   
            v.push_back(temp);
            temp.clear();            
        }
        return v;
    }
};
