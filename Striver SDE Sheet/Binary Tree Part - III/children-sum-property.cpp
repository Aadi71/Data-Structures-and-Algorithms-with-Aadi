// https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?

void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL) return;
    int childSum = 0;
    if(root -> left) childSum += root -> left -> data;
    if(root -> right) childSum += root -> right -> data;
    if (root->data > childSum) {
        if (root->left) root->left->data = root->data;
        else if (root->right) root->right->data = root->data;
    }
    changeTree(root -> left);
    changeTree(root -> right);
    int backSum = 0;
    if(root -> left) backSum += root -> left -> data;
    if(root -> right) backSum += root -> right -> data;
    if(root -> left || root -> right) root -> data = backSum;
}
