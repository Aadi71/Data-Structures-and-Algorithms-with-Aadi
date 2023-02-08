// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
    public:
    vector<int> topView(Node *root){
        if(!root) return {};
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            Node* node = q.front().first;
            int y = q.front().second;
            q.pop();
            if(m.find(y) == m.end()) m[y] = node -> data;
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
