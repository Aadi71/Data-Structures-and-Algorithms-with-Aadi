// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    Node* connect(Node* root) {
        Node* ptr = root;
        while(root && root -> left){
            Node* temp = root;
            while(temp){
                temp -> left -> next = temp -> right;
                temp -> right -> next = temp -> next == NULL ? NULL : temp -> next -> left;
                temp = temp -> next;
            }
            root = root -> left;
        }
        return ptr;
    }
};
