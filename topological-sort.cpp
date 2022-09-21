// https://www.codingninjas.com/codestudio/problems/topological-sort_982938?

#include <bits/stdc++.h> 

using namespace std;

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, vector<int>> &adj){
    visited[node] = 1;
    for(auto x: adj[node])
        if(!visited[x]) topoSort(x, visited, s, adj);
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i<edges.size(); i++)
        adj[edges[i][0]].push_back(edges[i][1]);
    
    vector<bool> visited(v);
    stack<int> s;
    for(int i = 0; i<v; i++)
        if(!visited[i])
            topoSort(i, visited, s, adj);
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
