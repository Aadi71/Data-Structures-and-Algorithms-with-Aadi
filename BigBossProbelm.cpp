/* Problem Statement 
Big Boss is one of popular reality shows in India. Every year a new variant of the show comes with a new set of policies. Candidates from all over the India can participate in the show. Suppose there are N candidates who participated in the 2021 show. All the participants had to go through the selection process. The survival in the show is based on the votes obtained from the viewers. Your task is to find the sum and average of the first K participants who have achieved lowest votes from the viewers. The problem can be solved with the help of binary search tree.

Your goal is to implement the C++ program for the following-

    Create a BST with the given data
    Perform an in-order traversal to sort all the candidates votes.
    Get the votes for the first K participants.
    Display the sum and average of the first K candidates votes.
First line of input shows the number of participants followed by their cote count in new lines. The last line shows the c=value of K. 
Sample Input:

7

54

51

49

52

75

74

85

3

Sample Output:

152

21.7

*/

//Method - 1 Insertion -> Inorder and pushing elements in a stack using STL  -> Result

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root, vector<int> & sorted){
    if(root == NULL){
        return;
    }
    inorder(root->left, sorted);
    sorted.push_back(root->data);
    inorder(root->right, sorted);
}

void insert(Node* root, int num){
    if(num < root->data){
        if(root->left == NULL){
            Node* newNode = new Node(num);
            root->left = newNode;
        }
        else{
            insert(root->left, num);
        }
    }
    else if(num > root->data){
        if(root->right == NULL){
            Node* newNode = new Node(num);
            root->right = newNode;
        }
        else{
            insert(root->right, num);
        }
    }
}

int main(){
    int n;
    vector<int> v;
    while(cin >> n){
        v.push_back(n);
    }
    int k = v[v.size()-1];
    v.pop_back();
    
    Node* root = new Node(v[0]);
    for(int i=1; i<v.size(); i++){
        insert(root, v[i]);
    }
   
    vector<int> sorted;
    inorder(root, sorted);
    
    int sum = 0;
    for(int i=0; i<k; i++){
        sum += sorted[i];
    }
    float avg =(float) sum/v.size();
    cout << sum << endl;
    cout << fixed << setprecision(1) << avg;
   
}


//Method - 2 Insertion -> Finding sum of first kthelement -> Result

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

Node * insert(Node * root, int data){
    if(!root){
        struct Node * node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        node->left = node->right = NULL;
        return node;
    }
    if(root->data < data){
        root ->right = insert(root -> right, data);
    }
            
    else{
        root->left = insert(root->left, data);
                
    }
    return root;
}

int ksmallestElementSumRec(Node *root, int k, int &count)
{
    if (root == NULL)
        return 0;
    if (count > k)
        return 0;
 
    int res = ksmallestElementSumRec(root->left, k, count);
    if (count >= k)
        return res;
 
    res += root->data;
 
    count++;
    if (count >= k)
      return res;
    return res + ksmallestElementSumRec(root->right, k, count);
}

void ksmallestElementSum(struct Node *root, int k)
{
   int count = 0;
   float sum = ksmallestElementSumRec(root, k, count);
   cout<<sum<<endl;
   cout<<fixed << setprecision(1)<<sum/7; 
}

int main()
{
    int n; cin>>n;
    Node * root = NULL;
    for(int i = 0; i<n;i++){
        int temp;cin>>temp;
        root = insert(root, temp);    
    }   
    int t;cin>>t;
    int arr[n]; 
    
    ksmallestElementSum(root, 3);
    
    return 0;
}


