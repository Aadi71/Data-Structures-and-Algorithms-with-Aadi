// https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = -1;
    while(node != NULL){
        if(node -> data == x) return node -> data;
        if(node -> data > x) ans = node -> data;
        node = node -> data > x ? node -> left : node -> right;
    }
    return ans;
}
