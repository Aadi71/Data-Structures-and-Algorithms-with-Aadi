// https://leetcode.com/problems/unique-binary-search-trees-ii/

class Solution {
public:
    vector<TreeNode*> build(int s, int e){
        vector<TreeNode*> trees;
        if(s > e){
            trees.push_back(NULL);
            return trees;
        }
        for(int i = s; i <= e; i++){
            vector<TreeNode*> left = build(s, i - 1);
            vector<TreeNode*> right = build(i + 1, e);
            for(int j = 0; j < left.size(); j++){
                TreeNode* l = left[j];
                for(int k = 0; k < right.size(); k++){
                    TreeNode* r = right[k];
                    TreeNode* node = new TreeNode(i);
                    node -> left = l;
                    node -> right = r;
                    trees.push_back(node);
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};
