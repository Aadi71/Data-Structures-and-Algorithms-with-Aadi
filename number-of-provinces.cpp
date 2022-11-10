// https://practice.geeksforgeeks.org/problems/number-of-provinces/1

class Solution {
    void dfs(int node, vector<vector<int>> adj, vector<bool> &vis){
        vis[node] = true;
        for(int i = 0; i<adj[node].size(); i++){
            if(adj[node][i] != 0 && !vis[i]){
                dfs(i, adj, vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> vis(V, false);
        int sum = 0;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                sum++;
            }
        }
        return sum;
    }
};
