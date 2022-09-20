// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, vector<int>> adj;
    
    for(int i = 0; i<edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }	
    
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto i: adj[f]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = f;
                q.push(i);
            }
        }
    }
    
    vector<int> ans;
    ans.push_back(t);
    while(t != s){
        t = parent[t];
        ans.push_back(t);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
