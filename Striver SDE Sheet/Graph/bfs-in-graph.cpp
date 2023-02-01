// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?

#include <bits/stdc++.h> 
using namespace std;

vector<int> BFS(int v, vector<pair<int, int>> edges){
    int n = edges.size();
    vector<int> adj[v];
    for(int i = 0; i<n; i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    for(int i=0; i<v; i++) sort(adj[i].begin(),adj[i].end());
    vector<int> vis(v, 0);
    queue<int> q;
    vector<int> res;
    for(int i = 0; i<v; i++){
        if(vis[i]) continue;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int n = q.size();
            int f = q.front();
            res.push_back(f);
            q.pop();
            for(auto it: adj[f]){
                if(!vis[it]) q.push(it);
                vis[it] = 1;
            }
        }
    }
    return res;
}
