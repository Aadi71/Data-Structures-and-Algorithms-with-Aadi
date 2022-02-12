// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

vector<int> leftView(Node *root)
{
   // Your code here
   vector <int> v;
   if(root == NULL) return v;
   
   queue <Node*> q;
   q.push(root);
   
   while(!q.empty()){
       int n = q.size();
       int t = q.size();
       while(n>0){
           Node* temp = q.front();
           q.pop();
           
           if(n == t) v.push_back(temp -> data);
           
           if(temp->left) q.push(temp->left);
           if(temp->right) q.push(temp->right);
           
           n--;
           
       }
       
   }
   
   return v;   
}
