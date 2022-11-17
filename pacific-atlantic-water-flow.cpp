// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, set<pair<int, int>> &s, int h){
        if(s.find({i, j}) != s.end() || i < 0 || j < 0 || i == heights.size() || j == heights[0].size() || heights[i][j] < h) return;
        s.insert({i, j});
        dfs(heights, i + 1, j, s, heights[i][j]);
        dfs(heights, i - 1, j, s, heights[i][j]);
        dfs(heights, i, j + 1, s, heights[i][j]);
        dfs(heights, i, j - 1, s, heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        set<pair<int, int>> pac;
        set<pair<int, int>> atl;
        for(int i = 0; i<m; i++){
            dfs(heights, i, 0, pac, heights[i][0]);
            dfs(heights, i, n - 1, atl, heights[i][n - 1]);
        }
        for(int j = 0; j<n; j++){
            dfs(heights, 0, j, pac, heights[0][j]);
            dfs(heights, m - 1, j, atl, heights[m - 1][j]);
        }
        vector<vector<int>> res;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(pac.find({i, j}) != pac.end() && atl.find({i, j}) != atl.end()){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};  
