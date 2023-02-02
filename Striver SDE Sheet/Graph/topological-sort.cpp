// https://www.codingninjas.com/codestudio/problems/982938

// Topological Sort by DFS
#include <bits/stdc++.h>
using namespace std; 
void dfs(stack<int> &st, vector<int> adj[], int node, vector<int> &vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]) dfs(st, adj, it, vis);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    for(int i = 0; i<e; i++) adj[edges[i][0]].push_back(edges[i][1]);
    stack<int> st;
    vector<int> vis(v, 0);
    for(int i = 0; i<v; i++) if(!vis[i]) dfs(st, adj, i, vis);
    vector<int> res; 
    while(!st.empty()){
        int t = st.top();
        res.push_back(t);
        st.pop();
    }
    return res;
}

