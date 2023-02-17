// https://www.codingninjas.com/codestudio/problems/893049?

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key){
    int successor = -1;
    int predecessor = -1;
    BinaryTreeNode<int>* root1 = root;
    while(root1 != NULL){
        if(root1 -> data < key){
            predecessor = root1 -> data;
            root1 = root1 -> right;
        }
        else root1 = root1 -> left;
    }
    while(root != NULL){
        if(root -> data > key){
            successor = root -> data;
            root = root -> left;
        }
        else root = root -> right;
    }
    return {predecessor, successor};
}
