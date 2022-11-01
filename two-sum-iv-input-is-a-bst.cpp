// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class Solution {
public:
    vector<int> v;
    void inOrder(TreeNode* node){
        if(!node) return;
        inOrder(node -> left);
        v.push_back(node -> val);
        inOrder(node -> right);
    }
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int i = 0, j = v.size() - 1;
        while(i<j){
            if (v[i] + v[j] == k) return true;
            else if (v[i] + v[j] > k) j--;
            else i++;
        }
        return false;   
    }
};
