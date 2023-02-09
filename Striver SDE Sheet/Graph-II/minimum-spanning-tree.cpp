// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution{
	public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sum = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt;
            for(auto it: adj[node])
                if(!vis[it[0]]) pq.push({it[1], it[0]});
        }
        return sum;
    }
};
