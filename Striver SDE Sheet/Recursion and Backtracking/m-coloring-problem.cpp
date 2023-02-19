// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

class Solution{
    bool isValid(bool graph[101][101], vector<int> &vis, int node, int n, int i){
        for(int j = 0; j<n; j++) if(j != node && graph[j][node] == 1 && vis[j] == i) return false;
        return true;
    }
    bool solve(bool graph[101][101], vector<int> &vis, int node, int n, int m){
        if(node == n) return true;
        for(int i = 0; i<m; i++){
            if(isValid(graph, vis, node, n, i)){
                vis[node] = i;
                if(solve(graph, vis, node + 1, n, m)) return true;
                vis[node] = -1;
            }
        }
        return false;
    }
public:
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> vis(n, -1);
        return solve(graph, vis, 0, n, m);
    }
};
