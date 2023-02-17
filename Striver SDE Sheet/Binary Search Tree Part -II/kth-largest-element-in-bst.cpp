// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

class Solution
{
    int ans;
    void count(Node* root, int &n){
        if(root == NULL) return;
        count(root -> left, n);
        n++;
        count(root -> right, n);
    }
    
    void solve(Node* root, int &ptr, int k){
        if(root == NULL) return;
        solve(root -> left, ptr, k);
        ptr++;
        if(ptr == k){
            ans = root -> data;
            return;
        }
        solve(root -> right, ptr, k);
    }
  
    public:
    int kthLargest(Node *root, int k)
    {
        int ptr = 0;
        int n = 0;
        count(root, n);
        solve(root, ptr, n - k + 1);
        return ans;
    }
};
