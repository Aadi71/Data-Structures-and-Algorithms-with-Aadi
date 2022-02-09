//https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

class Solution {
private:
    void inOrder(TreeNode* root, vector<int> &v1){
        if(!root) return;
        inOrder(root->left, v1);
        v1.push_back(root->val);
        inOrder(root->right, v1);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v1;
        if(!root) return v1;
        inOrder(root, v1);
        return v1;
    }
};

//https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution {
private:
    void preOrder(TreeNode * root, vector<int> &v1){
        if(!root) return;
        v1.push_back(root->val);
        preOrder(root -> left, v1);
        preOrder(root -> right, v1);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> v;
        if(!root) return v;
        preOrder(root, v);     
        return v;
    }
};

//https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
private:
    void postOrder(TreeNode * root, vector <int> &v){
        if(!root) return;
        postOrder(root->left, v);
        postOrder(root->right, v);
        v.push_back(root -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        postOrder(root, v);
        return v;
    }
};
