// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    void DFS(vector<int> adj[], vector<int> &vis, int node){
        vis[node] = 1;
        for(auto it: adj[node])
            if(!vis[it]) DFS(adj, vis, it);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int s = connections.size();
        if(n > s + 1) return -1;
        vector<int> adj[n];
        vector<int> vis(n, 0);
        for(int i = 0; i<s; i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int comp = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                DFS(adj, vis, i);
                comp++;
            }
        }
        return comp - 1;
    }
};
