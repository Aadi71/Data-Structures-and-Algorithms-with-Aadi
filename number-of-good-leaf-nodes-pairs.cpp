// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

class Solution {
public:
    int ans = 0;
    void traverseTree(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>> &umap, unordered_set<TreeNode*> &leafNodes) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node -> left == nullptr && node -> right == nullptr) {
                leafNodes.insert(node);
                continue;
            }
            if (node -> left) {
                q.push(node -> left);
                umap[node -> left].push_back(node);
                umap[node].push_back(node -> left);
            }
            if (node -> right) {
                q.push(node -> right);
                umap[node -> right].push_back(node);
                umap[node].push_back(node -> right);
            }
        }
    }

    void dfs(unordered_map<TreeNode*, vector<TreeNode*>> &umap, unordered_map<TreeNode*, bool> &vis, TreeNode* node, int distance, int currDist, unordered_set<TreeNode*> &leafNodes) {
        vis[node] = 1;
        for (auto itr: umap[node]) {
            if (!vis[itr] && currDist < distance) {
                if (leafNodes.find(itr) != leafNodes.end()) {
                    cout << itr -> val << endl;
                    vis[itr] = 1;
                    ans++;
                }
                if (currDist < distance) dfs(umap, vis, itr, distance, currDist + 1, leafNodes); else return;
            }
        }
    }

    void bfs(unordered_map<TreeNode*, vector<TreeNode*>> &umap, unordered_map<TreeNode*, bool> &vis, TreeNode* node, int distance, unordered_set<TreeNode*> &leafNodes) {
        queue<TreeNode*> bfsQueue;
        int currDist = 0;
        bfsQueue.push(node);
        vis[node] = 1;

        while(!bfsQueue.empty() && currDist <= distance) {
            int s = bfsQueue.size();
            while(s--) {
                TreeNode* f = bfsQueue.front();
                bfsQueue.pop();
                if (leafNodes.contains(f) && f != node) {
                    ans++;
                }
                for (auto itr: umap[f]) {
                    if (!vis[itr]) {
                        vis[itr] = 1;
                        bfsQueue.push(itr);
                    }
                }
            }
            currDist++;
        }
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> umap;
        unordered_set<TreeNode*> leafNodes;
        traverseTree(root, umap, leafNodes);
        
        for (auto node: leafNodes) {
            unordered_map<TreeNode*, bool> vis;
            bfs(umap, vis, node, distance, leafNodes);
        }
        return ans / 2;
    }
};
