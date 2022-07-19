// https://leetcode.com/problems/average-of-levels-in-binary-tree/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int temp = n;
            double sum = 0; 
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                sum += node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            v.push_back(sum / temp);
        }
        return v;
    }
};
