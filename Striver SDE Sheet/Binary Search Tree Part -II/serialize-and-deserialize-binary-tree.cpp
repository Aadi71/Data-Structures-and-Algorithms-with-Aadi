// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        queue<TreeNode*> q;
        q.push(root);
        string ans = to_string(root -> val);

        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* f = q.front();
                q.pop();
                if(f -> left == NULL) ans += ",#";
                else{
                    ans += ("," + to_string(f -> left -> val));
                    q.push(f -> left);
                }
                if(f -> right == NULL) ans += ",#";
                else{
                    ans += ("," + to_string(f -> right -> val));
                    q.push(f -> right);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#") node -> left = NULL;
            else{
                node -> left = new TreeNode(stoi(str));
                q.push(node -> left);
            }
            getline(s, str, ',');
            if(str == "#") node -> right = NULL;
            else{
                node -> right = new TreeNode(stoi(str));
                q.push(node -> right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
