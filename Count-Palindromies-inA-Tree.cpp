// A Binary Tree is constructed which represents various number palindromes on its paths starting from root to leaf. For example, the following tree represents palindromes like 121, 1331:

//                  1

//                 /  \

//               2      3

//              /     /   \

//             1     6     3

//                    \   /

//                     2 1

// The task is to count total number of palindromic paths in any given binary tree.

// Input is in the form of an array, where nodes are entered in level order, where empty nodes are represented by -1. The first line of input represents total nodes including the empty nodes in the complete binary tree. Output is the total count of nodes.


#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int n)   
{ 
    Node *ptr=new Node; 
    ptr->data=n; 
    ptr->left=ptr->right=NULL; 
    return ptr; 
} 
Node * createBalancedBST(int arr[], int start, int end) 
{ 
    if(start > end) 
        return NULL; 
    int mid = (start+end)/2; 
    Node *root = newNode(arr[mid]); 
    root->left = createBalancedBST(arr, start, mid-1); 
    root->right = createBalancedBST(arr, mid+1, end); 
    return root; 
}  
bool hasPath(Node *root, vector<int>& arr, int x)
{
    if (!root)
        return false;
    arr.push_back(root->data);   
    if (root->data == x)   
        return true;
    if (hasPath(root->left, arr, x) ||
        hasPath(root->right, arr, x))
        return true;
    arr.pop_back();
    return false;           
}
int findHeight(struct Node* node)
{
    if (node == NULL)
        return 0;
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
     
    return 1 + (leftHeight > rightHeight ?leftHeight : rightHeight);
}
bool isPalindrome(string str)
{
    int l = 0;
    int h = str.length() - 1;
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    return true;
}
bool isPathPal(int* path, int index)
{
    int i = 0;
    string s;
    while (i <= index) {
        s += to_string(path[i]);
        i += 1;
    }
    return isPalindrome(s);
}
void printPalPath(int* path, int index)
{
    for (int i = 0; i < index; i++) ;
    cout<<index/2;
    exit(0);
}
void printPath(struct Node* node,int* path, int index)
{
    if (node == NULL) 
    {
        return;
    }
    path[index] = node->data;
    printPath(node->left, path,index + 1);
    printPath(node->right, path,index + 1);
    if (node->left == NULL &&node->right == NULL) 
    {
        if (isPathPal(path, index)) 
        {
            printPalPath(path, index + 1);
        }
    }
    else
    {
        cout<<"1";
        exit(0);
    }
}
void PalindromicPath(struct Node* node)
{
    int height = findHeight(node);
    int* path = new int[height];
    memset(path, 0, sizeof(path));
    printPath(node, path, 0);
}
 
int main()
{
    int size,n; 
    cin>>size;   
    int a[size]; 
    Node* root; 
    for(int i=0;i<size;i++) 
    { 
        cin>>a[i];    
    } 
    sort((a), a + size); 
    root = createBalancedBST(a, 0, size-1);
    PalindromicPath(root);
    return 0;
}
