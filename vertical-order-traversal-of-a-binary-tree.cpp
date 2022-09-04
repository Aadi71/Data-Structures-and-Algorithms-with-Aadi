// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    struct node{
        int val, xaxis, yaxis;
    };
    static bool comp(node a, node b){
        if(a.yaxis == b.yaxis && a.xaxis == b.xaxis) return a.val < b.val;
        else if(a.xaxis == b.xaxis) return a.yaxis < b.yaxis;
        return a.xaxis < b.xaxis;
    }
    void traversal(TreeNode* root, int x, int y, vector<node> &nodes){
        if(root == NULL) return;
        node n;
        n.val = root -> val;
        n.xaxis = x;
        n.yaxis = y;
        nodes.push_back(n);
        if(root -> left) traversal(root -> left, x - 1, y + 1, nodes);
        if(root -> right) traversal(root -> right, x + 1, y + 1, nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<node> nodes;
        traversal(root, 0, 0, nodes);
        vector<vector<int>> v;
        sort(nodes.begin(), nodes.end(), comp);
        int i = 0;
        int m = nodes[0].xaxis;
        vector<int> temp;
        while(i < nodes.size()){
            if(nodes[i].xaxis == m){
                temp.push_back(nodes[i].val);
            }
            else{
                v.push_back(temp);
                temp.clear();
                temp.push_back(nodes[i].val);                
            }
            m = nodes[i].xaxis;
            i++; 
        }
        v.push_back(temp);
        return v;   
    }
};
