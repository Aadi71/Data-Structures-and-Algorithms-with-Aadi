// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


// Brute Force - BFS with O(n) time complexity
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int temp = n;
            while(n--){
                Node* f = q.front();
                q.pop();
                if(n == 0) f -> next = NULL;
                else f -> next = q.front();
                q.push(f);
            }
            n = temp;
            while(n--){
                Node* f = q.front();
                q.pop();
                if(f -> left) q.push(f -> left);
                if(f -> right) q.push(f -> right);
            }
        }
        return root;
    }
};

// Space Optimized Approach of O(1)
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
