// https://leetcode.com/problems/course-schedule-ii/description/

// TC: O(V+E) SC: O(V+E)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        vector<int> inDegree(n);
        queue<int> q;
        unordered_map<int, vector<int>> umap;
        vector<int> res;

        for (auto itr: pr) {
            umap[itr[1]].push_back(itr[0]);
            inDegree[itr[0]]++;
        }

        for (int i = 0; i < n; i++) if (inDegree[i] == 0) q.push(i);

        while(!q.empty()) {
            int f = q.front();
            q.pop();
            res.push_back(f);

            for (auto itr: umap[f]) {
                inDegree[itr]--;
                if (inDegree[itr] == 0) q.push(itr);
            }
        }

        for (auto itr: inDegree) if (itr > 0) return {};
        return res;
    }
};

