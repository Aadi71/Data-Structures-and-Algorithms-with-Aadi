// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(!root) return {{}};
        // Node, vertical, level
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        map<int, int> m;
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            Node* node = f.first;
            int y = f.second;
            m[y] = node -> data;
            if(node -> left) q.push({node -> left, y - 1});
            if(node -> right) q.push({node -> right, y + 1});
        }
        vector<int> ans;
        for(auto it: m){
            ans.push_back(it.second);
        }
        return ans;
    }
};
