// https://practice.geeksforgeeks.org/problems/mirror-tree/1

class Solution {
  public:
    Node* solve(Node* node){
        if(node == NULL) return NULL;
        Node* temp = node -> left;
        node -> left = solve(node -> right);
        node -> right = solve(temp);
        return node;
    }
    void mirror(Node* root) {
        root = solve(root);
    }
};
