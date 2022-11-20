// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    void DFS(vector<int> adj[], int node, int n, vector<int> temp, vector<vector<int>> &ans){
        temp.push_back(node);
        if(node == n - 1){
            ans.push_back(temp);
            return;
        }
        for(auto it: adj[node])
            DFS(adj, it, n, temp, ans);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> temp;
        vector<vector<int>> ans;
        DFS(adj, 0, n, temp, ans);
        return ans;
    }
};
