// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> v;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp){
            if(temp -> right) q.push(temp -> right);
            if(temp -> left) q.push(temp -> left);
            v.insert(v.begin(), temp -> data);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    return v;
}
