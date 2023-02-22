// https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            int mini = q.front().second;
            int maxi;
            for(int i = 0; i < n; i++){
                auto f = q.front();
                q.pop();
                int curr = f.second - mini;
                if(i == n - 1) maxi = curr;    
                if(f.first -> left) q.push({f.first -> left, (long long)curr * 2 + 1});
                if(f.first -> right) q.push({f.first -> right, (long long)curr * 2 + 2});
            }
            ans = max(ans, maxi + 1);
        }
        return ans;
    }
};
