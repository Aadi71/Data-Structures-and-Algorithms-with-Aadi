// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

// Optimized and T.C: O(n) solution. All the nodes having indegree = 0 cannot be visited by any other node, so only those nodes makes the answer.

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans, vis(n, 0);
        for(int i = 0; i<edges.size(); i++) vis[edges[i][1]] = 1;
        for(int i = 0; i<n; i++) if(vis[i] == 0) ans.push_back(i);
        return ans;
    }
};


// Brute Force: I am doing topo sort so that I can start with the nodes first that are having indegree = 0.

class Solution {
public:
    void dfs(vector<int> adj[], stack<int> &s, int node, vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]) if(!vis[it]) dfs(adj, s, it, vis);
        s.push(node);
    }
    void dfs1(vector<int> adj[], int node, vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]) if(!vis[it]) dfs1(adj, it, vis);
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(n, 0);
        stack<int> s;
        for(int i = 0; i<n; i++) if(!vis[i]) dfs(adj, s, i, vis);
        vector<int> topo;
        while(!s.empty()){
            int f = s.top();
            topo.push_back(f);
            s.pop();
        }
        vector<int> res;
        for(int i = 0; i<n; i++) vis[i] = 0;
        for(int i = 0; i<topo.size(); i++){
            if(!vis[topo[i]]){
                res.push_back(topo[i]);
                dfs1(adj, topo[i], vis);
            }
        }
        return res;
    }
};


