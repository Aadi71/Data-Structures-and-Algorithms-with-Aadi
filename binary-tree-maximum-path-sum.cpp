// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int maxPathSumUtil(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        int left = maxPathSumUtil(root -> left, ans);
        int right = maxPathSumUtil(root -> right, ans);
            
        int nodeMax = max(max(root -> val, root -> val + left + right), 
                      max(root -> val + left, root -> val + right));
        
        ans = max(ans, nodeMax);
        
        int singlePathSum = max(root -> val, max(root->val+left, root->val+right));
        
        return singlePathSum;
        
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSumUtil(root, ans);
        return ans;
    }
};
