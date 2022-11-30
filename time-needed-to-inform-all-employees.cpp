// https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int dfs(int id, vector<int> adj[], vector<int> &informTime){
        int maxi = 0;
        for(auto i: adj[id]) maxi = max(maxi, dfs(i, adj, informTime));
        return informTime[id] + maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> vis(n, 0);
        int timer = 0;
        vector<int> adj[n];
        for(int i = 0; i<manager.size(); i++){
            if(manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }
        return dfs(headID, adj, informTime);
    }
};
