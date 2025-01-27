// https://leetcode.com/problems/course-schedule/
// TC: O(V+E) SC: O(V+E)
// BFS Solution: Kahn's Algorithm

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        unordered_map<int, vector<int>> umap;
        vector<int> inDegree(n);
        queue<int> q;
        for (auto itr: pr) {
            umap[itr[1]].push_back(itr[0]);
            inDegree[itr[0]]++;
        }
        for (int i = 0; i < n; i++) if (inDegree[i] == 0) q.push(i);
        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto itr: umap[front]) {
                inDegree[itr]--;
                if (inDegree[itr] == 0) q.push(itr);
            }
        }

        for (auto itr: inDegree) if (itr > 0) return false;
        return true;
    }
};


// DFS Solution
// TC: O(V+E) SC: O(V+E)

class Solution {
public:
    bool isCycle(int node, unordered_map<int, vector<int>> &umap, vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto itr: umap[node]) {
            if (!vis[itr] && isCycle(itr, umap, vis, pathVis)) return true;
            else if (pathVis[itr]) return true;
        }

        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pr) {
        unordered_map<int, vector<int>> umap;
        for (auto itr: pr) umap[itr[1]].push_back(itr[0]);
        
        vector<int> vis(n, 0), pathVis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i] && isCycle(i, umap, vis, pathVis)) return false;
        }
        return true;
    }
};
