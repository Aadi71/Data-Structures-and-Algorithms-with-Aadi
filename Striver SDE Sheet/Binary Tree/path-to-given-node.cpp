// https://www.interviewbit.com/problems/path-to-given-node/
 
void getPath(TreeNode* root, int x, vector<int> temp, vector<int> &path){
    if(root -> val == x){
        path = temp;
        return;
    }
    if(root -> left) {
        temp.push_back(root -> left -> val);
        getPath(root -> left, x, temp, path);
        temp.pop_back();
    }
    if(root -> right) {
        temp.push_back(root -> right -> val);
        getPath(root -> right, x, temp, path);
        temp.pop_back();
    }

} 
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    getPath(A, B, {A -> val}, path);
    return path;
}
