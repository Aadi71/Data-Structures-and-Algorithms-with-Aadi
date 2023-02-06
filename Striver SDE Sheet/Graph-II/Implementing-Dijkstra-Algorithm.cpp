// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/

class Solution{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 1e9);
        vis[S] = 0;
        pq.push({0, S});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int w = it[1];
                int n = it[0];
                if(dis + w < vis[n]){
                    vis[n] = dis + w;
                    pq.push({vis[n], n});
                }
            }
        }
        return vis;
    }
};
