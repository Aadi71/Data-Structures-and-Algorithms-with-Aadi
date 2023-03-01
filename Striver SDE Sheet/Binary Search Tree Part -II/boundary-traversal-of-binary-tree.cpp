// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
public:
    vector<int> ans;
    void leftBoundary(Node * root){
        if(root -> left == NULL && root -> right == NULL) return;
        ans.push_back(root -> data);
        if(root -> left) leftBoundary(root -> left);
        else leftBoundary(root -> right);
    }
    void leafBoundary(Node * root){
        if (root -> left == NULL && root -> right == NULL){
            ans.push_back(root -> data);
            return;
        }
        if (root -> left) leafBoundary(root -> left);
        if (root -> right) leafBoundary(root -> right);
    }
    void rightBoundary(Node * root){
        if(root -> left == NULL && root -> right == NULL) return;
        if(root -> right) rightBoundary(root -> right);
        else rightBoundary(root -> left);
        ans.push_back(root -> data);
    }
    vector <int> boundary(Node *root){
        if(root == NULL) return {};
        ans.push_back(root -> data);
        if(root -> left){
            leftBoundary(root -> left);
            leafBoundary(root -> left);    
        }
        if(root -> right){
            leafBoundary(root -> right);    
            rightBoundary(root -> right);
        }
    
        return ans;
    }
};
