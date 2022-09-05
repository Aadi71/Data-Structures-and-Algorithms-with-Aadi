// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(!root) return v;
        vector <int> temp;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i<n;i++){
                Node* front = q.front();
                q.pop();
                temp.push_back(front->val);
                for(int j = 0; j< front -> children.size(); j++){
                    q.push(front->children[j]);
                }
            }
            v.push_back(temp);
            temp.clear();   
        }
        return v;
    }
};
