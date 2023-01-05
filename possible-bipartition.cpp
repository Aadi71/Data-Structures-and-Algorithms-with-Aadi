// https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool bfs(int src, vector<int> adj[], vector<int> &vis){
        queue<int> q;
        q.push(src);
        vis[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i: adj[node]){
                if(vis[i] == -1){
                    vis[i] = 1 - vis[node];
                    q.push(i);
                }
                else if(vis[i] == vis[node]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n + 1];
        for(int i = 0; i<dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> vis(n + 1, -1);
        for(int i = 1; i<=n; i++){
            if(vis[i] == -1){
                if(bfs(i, adj, vis) == false) return false;
            }
        }
        return true;
    }
};
