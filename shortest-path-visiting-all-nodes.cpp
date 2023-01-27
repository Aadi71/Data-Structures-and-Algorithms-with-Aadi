// https://leetcode.com/problems/shortest-path-visiting-all-nodes/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        // node, mask, cost
        queue<pair<int, pair<int, int>>> q;
        // node, mask
        set<pair<int, int>> s;
        for(int i = 0; i<n; i++){
            q.push({i, {1 << i, 0}});
            s.insert({i, 1 << i});
        }
        int ans = (1 << n) - 1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it.second.first == ans) return it.second.second;
            for(auto i: graph[it.first]){
                int curr = it.second.first;
                curr = curr | (1 << i);
                if(s.find({i, curr}) == s.end()){
                    q.push({i, {curr, it.second.second + 1}});
                    s.insert({i, curr});
                }
            } 
        }
        return -1;
    }
};
