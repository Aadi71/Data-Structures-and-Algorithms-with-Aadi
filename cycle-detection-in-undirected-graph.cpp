// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?

// BFS

#include <bits/stdc++.h>
bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj){
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    
    queue<int>q;
    q.push(src);
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        
        for(auto x: adj[f]){
            if(visited[x] == true && x != parent[f]) return true;
            else if(!visited[x]){
                q.push(x);
                visited[x] = 1;
                parent[x] = f;
            }
        }
    }
    return false;
}

// DFS

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj){
    visited[node] = true;
    for(auto x: adj[node]){
        if(!visited[x]){
            bool cycleDetected = isCyclicDFS(x, node, visited, adj);
            if(cycleDetected) return true;
        }
        else if(x != parent) return true;
    }
    return false;
}


// Main Solution
