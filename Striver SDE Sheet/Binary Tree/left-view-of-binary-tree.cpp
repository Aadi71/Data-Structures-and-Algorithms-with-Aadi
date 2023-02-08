// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
 
vector<int> leftView(Node *root){
   if(!root) return {};
   queue<Node*> q;
   q.push(root);
   vector<int> ans;
   while(!q.empty()){
       int n = q.size();
       ans.push_back(q.front() -> data);
       while(n--){
           Node* node = q.front();
           q.pop();
           if(node -> left) q.push(node -> left);
           if(node -> right) q.push(node -> right);
       }
   }
   return ans;
}
