// https://leetcode.com/problems/path-sum-ii/

class Solution {
    private:
    void check(TreeNode* node, int sum, vector<vector<int>> &main, vector<int> &temp){
        if(node == NULL) return;
        temp.push_back(node -> val);
        if(node -> left == NULL && node -> right == NULL && node -> val == sum) main.push_back(temp);
        check(node -> left, sum - node -> val, main, temp);
        check(node -> right, sum - node -> val, main, temp);
        temp.pop_back();
    }
    public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> main;
        vector<int> temp;
        check(root, targetSum, main, temp);
        return main;
    }
};
