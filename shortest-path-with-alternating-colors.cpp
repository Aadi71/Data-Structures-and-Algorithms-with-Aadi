// https://leetcode.com/problems/shortest-path-with-alternating-colors/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1);
        vector<vector<int>> vis(n, vector<int> (2, 0));
        queue<pair<int, pair<int, int>>> q;    
        vector<pair<int, int>> adj[n];
        // red = 0, blue = 1
        for(int i = 0; i<redEdges.size(); i++) adj[redEdges[i][0]].push_back({redEdges[i][1], 0});
        for(int i = 0; i<blueEdges.size(); i++) adj[blueEdges[i][0]].push_back({blueEdges[i][1], 1});

        q.push({0, {0, -1}});
        // q = {node, {steps, color}}
        vis[0][0] = 1; vis[0][1] = 1;
        res[0] = 0;
        while(!q.empty()){
            pair<int, pair<int, int>> f = q.front();
            q.pop();
            int node = f.first; int steps = f.second.first; int col = f.second.second;
            for(auto it: adj[node]){
                if(!vis[it.first][it.second] && col != it.second){
                    vis[it.first][it.second] = 1;
                    q.push({it.first, {steps + 1, it.second}});
                    if(res[it.first] == -1) res[it.first] = 1 + steps;
                }
            }
        }
        return res;
    }
};
