// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Recursive Solution. Space Complextiy: O(H) Where H, is the the height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};

// Iterative using queue. Space Complextiy: O(N) Where N, is the number of nodes in the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            ans++;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left) q.push(node -> left); 
                if(node -> right) q.push(node -> right); 
            }
        }
        return ans;
    }
};
