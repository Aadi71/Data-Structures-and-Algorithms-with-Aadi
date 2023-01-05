// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool bfs(int src, vector<vector<int>>& graph, vector<int> &vis){
        queue<int> q;
        q.push(src);
        vis[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 0; i<graph[node].size(); i++){
                if(vis[graph[node][i]] == -1){
                    vis[graph[node][i]] = 1 - vis[node];
                    q.push(graph[node][i]);
                }
                else if(vis[graph[node][i]] == vis[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i<n; i++){
            if(vis[i] == -1){
                if(bfs(i, graph, vis) == false) return false;
            }
        }
        return true;
    }
};
