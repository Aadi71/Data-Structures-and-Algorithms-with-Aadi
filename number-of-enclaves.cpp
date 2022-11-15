// https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int flag){
        grid[i][j] = -1;
        int a[] = {0, 0, -1, 1};
        int b[] = {-1, 1, 0, 0};
        for(int k = 0; k<4; k++){
            int inew = i + a[k];
            int jnew = j + b[k];
            if(inew >= 0 && jnew >= 0 && inew < grid.size() && jnew < grid[0].size() && grid[inew][jnew] == 1){
                grid[inew][jnew] = flag;
                dfs(grid, inew, jnew, flag);
            }
        }   
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int area = 0;
        for(int i = 0; i<row; i++){
            if(grid[i][0] == 1) dfs(grid, i, 0, -1);
            if(grid[i][col - 1] == 1) dfs(grid, i, col - 1, -1);
        }
        for(int j = 0; j<col; j++){
            if(grid[0][j] == 1) dfs(grid, 0, j, -1);
            if(grid[row - 1][j] == 1) dfs(grid, row - 1, j, -1);
        }
        for(int i = 1; i < row - 1; i++){
            for(int j = 1; j < col - 1; j++){
                if(grid[i][j] == 1){
                    area++;
                }
            }
        }
        return area;
    }
};
