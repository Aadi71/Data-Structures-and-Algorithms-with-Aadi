// https://www.codingninjas.com/codestudio/problems/topological-sort_982938?

#include <bits/stdc++.h> 


// DFS

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


// BFS: Kahn's Algorithm    

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> inDegree(v);
    for(auto x: adj){
        for(auto y: x.second) inDegree[y]++;
    }
    queue<int> q;
    for(int i = 0; i<v; i++){
        if(inDegree[i] == 0) q.push(i);   
    }
    
    // BFS
    vector<int> ans;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        ans.push_back(f);
        
        for(auto x: adj[f]){
            inDegree[x]--;
            if(inDegree[x] == 0) q.push(x);
        }
    }
    return ans;
    
    
}
