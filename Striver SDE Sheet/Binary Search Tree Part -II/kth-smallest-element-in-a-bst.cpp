// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    int ans;
    void solve(TreeNode* root, int &ptr, int k){
        if(root == NULL) return;
        solve(root -> left, ptr, k);
        ptr++;
        if(ptr == k){
            ans = root -> val;
            return;
        }
        solve(root -> right, ptr, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ptr = 0;
        solve(root, ptr, k);
        return ans;
    }
};
