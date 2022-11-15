// https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, int flag){
        grid[i][j] = flag;
        int a[] = {0, 0, -1, 1};
        int b[] = {-1, 1, 0, 0};
        for(int k = 0; k<4; k++){
            int inew = i + a[k];
            int jnew = j + b[k];
            if(inew >= 0 && jnew >= 0 && inew < grid.size() && jnew < grid[0].size() && grid[inew][jnew] == 0)
                DFS(grid, inew, jnew, flag);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int flag = -1;
        int row = grid.size();
        int col = grid[0].size();
        for(int j = 0; j<grid[0].size(); j++)
            if(grid[0][j] == 0) DFS(grid, 0, j, flag);
        for(int j = 0; j<grid[0].size(); j++)
            if(grid[row - 1][j] == 0) DFS(grid, row - 1, j, flag);
        for(int i = 0; i<grid.size(); i++)
            if(grid[i][0] == 0) DFS(grid, i, 0, flag);
        for(int i = 0; i<grid.size(); i++)
            if(grid[i][col - 1] == 0) DFS(grid, i, col - 1, flag);
        flag = 2;
        for(int i = 1; i< row - 1; i++){
            for(int j = 1; j< col - 1; j++){
                if(grid[i][j] == 0){
                    DFS(grid, i, j, flag);
                    ans++;
                }
            }
        }
        return ans;
    }
};
