// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &vis, int node, vector<int> &temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]) dfs(adj, vis, it, temp);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> res;
    vector<int> vis(V, 0);
    vector<int> adj[V];
    for(int i = 0; i<E; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(adj, vis, i, temp);
            res.push_back(temp);
        }
    }
    return res;
}
