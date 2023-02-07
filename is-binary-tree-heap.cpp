// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

class Solution {
  public:
    bool isHeap(struct Node* tree) {
        queue<Node*> q;
        q.push(tree);
        bool flag = false;
        while(!q.empty()){
            Node* root = q.front();
            q.pop();
            if(root -> left){
                if(flag || root -> data < root -> left -> data) return false;
                q.push(root -> left);
            }
            else flag = false;
            
            if(root -> right){
                if(flag || root -> data < root -> right -> data) return false;
                q.push(root -> right);
            }
            else flag = true;
        }
    return true;
    }
};
