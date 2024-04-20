// https://leetcode.com/problems/island-perimeter/description/

class Solution {
public:
    vector<int> a = {-1, 0, 0, 1};
    vector<int> b = {0, 1, -1, 0};

    void dfs(int r, int c, int i, int j, vector<vector<int>>& grid, int &ans) {
        grid[i][j] = 2;
        for(int k = 0; k < 4; k++) {
            int inew = i + a[k];
            int jnew = j + b[k];
            if (inew < 0 || inew >= r) ans++;
            else if (jnew < 0 || jnew >= c) ans++;
            else if (grid[inew][jnew] == 0) ans++;
            else if (grid[inew][jnew] == 1) dfs(r, c, inew, jnew, grid, ans);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if (grid[i][j] == 1) dfs(r, c, i, j, grid, ans);
            }
        }
        return ans;
    }
};
