// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

// Brute-Force
class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root, vector<int> v){
        v[root -> val]++;
        if(root -> left) solve(root -> left, v);
        if(root -> right) solve(root -> right, v);
        if(!root -> left && !root -> right){
            int count = 0;
            for(int i = 0; i<v.size(); i++){
                count += v[i] % 2;
            }
            if(count <= 1) ans++;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL) return 0;
        vector<int> v(10, 0);
        solve(root, v);
        return ans;
    }
};

// Recursive Preorder Traversal and bit manipulation

class Solution {
public:
    int ans = 0;
    void solve(TreeNode* node, int c){
        if(node != NULL){
            c = c ^ (1 << node -> val);
            if(node -> left == NULL && node -> right == NULL)
                if((c & (c-1)) == 0) 
                    ans++;
            solve(node -> left, c);
            solve(node -> right, c);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};
