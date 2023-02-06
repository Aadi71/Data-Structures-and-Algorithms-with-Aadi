// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    void dfs(vector<int> adj[], vector<int> &vis, int node, bool &flag){
        for(auto it: adj[node]){
            if(vis[it] == 0){
                vis[it] = vis[node] * -1;
                dfs(adj, vis, it, flag);
            }
            else if(vis[it] == vis[node]){ 
                flag = false;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        // Let the two sets be -1 and 1.
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                bool flag = true;
                vis[i] = 1;
                dfs(adj, vis, i, flag);
                if(flag == false) return false;
            }
        }
        return true;
    }
};
