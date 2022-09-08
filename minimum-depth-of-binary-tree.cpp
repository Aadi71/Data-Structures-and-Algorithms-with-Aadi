// https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int i = 0;
        while(!q.empty()){
            i++;
            int n = q.size();
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left == NULL && node -> right == NULL) return i;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);     
            }
        }
        return -1;
    }
};
