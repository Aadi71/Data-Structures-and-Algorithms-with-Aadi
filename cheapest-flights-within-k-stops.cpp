// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// BFS - Not Accepted(TLE)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(int i = 0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        int mini = INT_MAX;
        while(!q.empty() && k >= 0){
            int n = q.size();
            while(n--){
                pair<int, int> f = q.front();
                q.pop();
                int node = f.first; int dist = f.second;
                for(auto it: adj[node]){
                    int a = it.first, b = it.second;
                    if(mini <= dist + b) continue;
                    q.push({a, dist + b});
                    if(a == dst) mini = min(mini, dist + b);
                }      
            }
            k--;
        }
        if(mini != INT_MAX) return mini;
        return -1;
    }
};


// Dijkstra Algorithm using queue only

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // {stops, {node,cost}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops > k) break;
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjWt = it.second;
                if(cost + adjWt < dist[adjNode]) {
                    dist[adjNode] = cost + adjWt;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }   
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};



















