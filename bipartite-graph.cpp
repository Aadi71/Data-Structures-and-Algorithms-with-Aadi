// https://practice.geeksforgeeks.org/problems/bipartite-graph/

class Solution {
    bool bfs(int src, vector<int>adj[], vector<int> &color){
        color[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto i: adj[f]){
                if(color[i] == -1){
                    color[i] = !color[f];
                    q.push(i);
                }
                else if(color[i] == color[f]) return false;
            }
        }
        return true;
    }
    bool dfs(int node, vector<int>adj[], int col, vector<int> &color){
        color[node] = col;
        for(auto i: adj[node]){
            if(color[i] == col) return false;
            else if(color[i] == -1){
                if(!dfs(i, adj, !col, color)) return false; 
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
//          vector<int> color(V, -1);
// 	    for(int i = 0; i<V; i++){
// 	        if(color[i] == -1){
// 	            if(bfs(i, adj, color) == false) return false;
// 	        }
// 	    }
	vector<int> color(V, -1);
	    for(int i = 0; i<V; i++){
	        if(color[i] == -1){
	            if(dfs(i, adj, 0, color) == false) return false;
	        }
	    }
	return true;
  }
};
