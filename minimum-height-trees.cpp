// https://leetcode.com/problems/minimum-height-trees/description

// Brute Force Approach, find the maxHeights for all the nodes and pick out the nodes having minimum node
class Solution {
public:
    int maxHeight(int node, int n, vector<int> adj[]) {
        int height = 0;
        queue<int> q;
        vector<int> vis(n, 0);
        vis[node] = 1;
        q.push(node);
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                int f = q.front();
                q.pop();
                for(auto itr: adj[f]) {
                    if (!vis[itr]) {
                        q.push(itr);
                        vis[itr] = 1;
                    }
                }
            }
            height++;
        }
        return height;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int, int> nodeVsHeight;
        int minHeight = INT_MAX;
        for(int i = 0; i < n; i++){
            int height = maxHeight(i, n, adj);
            minHeight = min(minHeight, height);
            nodeVsHeight[i] = height;
        }
        vector<int> ans;
        for (auto itr: nodeVsHeight) if (itr.second == minHeight) ans.push_back(itr.first);
        return ans;
    }
};

// Optimized Approach, will remove leaf approach
// Approach Idea: https://leetcode.com/problems/minimum-height-trees/description/comments/2092652
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            inDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) if (inDegree[i] == 1) q.push(i), inDegree[i]--;
        while(!q.empty()) {
            int s = q.size();
            ans.clear();
            while(s--) {
                int node = q.front();
                ans.push_back(node);
                q.pop();
                for(auto itr: adj[node]) {
                    if (inDegree[itr]) inDegree[itr]--;
                    if (inDegree[itr] == 1) q.push(itr);
                }
            }
        }
        return ans;
    }
};
