// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:
    void dfs(vector<int> adj[], int node, int &sum, vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[abs(it)]){
                if(it > 0) sum++;
                dfs(adj, abs(it), sum, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i = 0; i<n-1; i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
        int sum = 0;
        vector<int> vis(n, 0);
        dfs(adj, 0, sum, vis);
        return sum;
    }
};
