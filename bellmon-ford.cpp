// https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977?

#include <bits/stdc++.h> 
using namespace std;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u] != 1e9 && (dist[u] + wt < dist[v])) dist[v] = dist[u] + wt;
        }
    }
    
    // Checking if there is any negative cycle present or not.
    bool flag = 0;
    for(int j = 0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u] != 1e9 && (dist[u] + wt < dist[v])) flag = 1;
    }
  
  
    if(flag == 1) return -1;  
    return dist[dest];
    
}
