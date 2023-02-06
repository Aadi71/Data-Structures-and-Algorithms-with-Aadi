// Bipartite-Check-Using-BFS
// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
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
            if(vis[i] != 0) continue;
            queue<int> q;
            q.push(i);
            vis[i] = -1;
            while(!q.empty()){
                int f = q.front();
                q.pop();
                for(auto it: adj[f]){
                    if(vis[it] == 0){
                        q.push(it);
                        vis[it] = -1 * vis[f];
                    }
                    else if(vis[it] == vis[f]) return false;
                }
            }
        }
        return true;
    }
};
