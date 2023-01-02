// https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        for(int i = 0; i<n; i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                inDegree[i]++;
            }
        }
        vector<int> res;
        queue<int> q;
        for(int i = 0; i<n; i++) if(inDegree[i] == 0) q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
