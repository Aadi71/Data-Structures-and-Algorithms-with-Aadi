// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

class Solution {
public:
    void solve(Node* root, vector<int> &v){
        v.push_back(root -> val);
        for(int i = 0; i<root-> children.size(); i++) solve(root -> children[i], v);
    }
    vector<int> preorder(Node* root) {
        vector<int> v;
        if(!root) return v;
        
        solve(root, v);
        return v;        
    }
};
