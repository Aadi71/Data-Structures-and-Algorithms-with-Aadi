// https://www.codingninjas.com/codestudio/problems/985311?

#include<bits/stdc++.h>
using namespace std;

void dfs_finish_time(vector<int> adj[], vector<int> &vis, stack<int> &st, int node){
    vis[node] = 1;
    for(auto it: adj[node])
        if(!vis[it]) 
            dfs_finish_time(adj, vis, st, it);
    st.push(node);
}

void dfs(vector<int> adjR[], vector<int> &vis, int node, vector<int> &temp){
    temp.push_back(node);
    vis[node] = 1;
    for(auto it: adjR[node])
        if(!vis[it]) 
            dfs(adjR, vis, it, temp);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){
    vector<int> adj[n];
    for(int i = 0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<vector<int>> v;
    vector<int> vis(n, 0);
    stack<int> st;
    for(int i = 0; i<n; i++) 
        if(!vis[i]) 
            dfs_finish_time(adj, vis, st, i);
    for(int i = 0; i<n; i++) vis[i] = 0;

    int ans = 0;
    vector<int> adjR[n];
    for(int i = 0; i<edges.size(); i++){
        adjR[edges[i][1]].push_back(edges[i][0]);
    }
    while(!st.empty()){
        int f = st.top();
        st.pop();
        if(!vis[f]){
            vector<int> temp;
            ans++;
            dfs(adjR, vis, f, temp);
            v.push_back(temp);
        }
    }
    return v;
}
