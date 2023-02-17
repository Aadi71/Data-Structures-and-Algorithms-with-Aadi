// https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457

int floorInBST(TreeNode<int> * root, int x){
    int ans = -1;
    while(root != NULL){
        if(root -> val == x) return root -> val;
        if(root -> val <= x){
            ans = root -> val;
            root = root -> right;
        }
        else root = root -> left; 
    }
    return ans;
}
