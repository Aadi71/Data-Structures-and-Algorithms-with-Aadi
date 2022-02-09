//Binary Tree lvl Order Traversal

void lvlOrder(struct Node * root){
    if(root == NULL) return;
    queue <Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * node = q.front();
        q.pop();
        if(node){
            cout<<node->data<<" ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        else if(!q.empty()) q.push(NULL);
    }
}


// https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/

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
