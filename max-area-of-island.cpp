// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, int &area){
        grid[i][j] = 2;
        int a[] = {0, 0, -1, 1};
        int b[] = {-1, 1, 0, 0};
        for(int k = 0; k<4; k++){
            int inew = a[k] + i;
            int jnew = b[k] + j;
            if(inew >= 0 && jnew >= 0 && inew < grid.size() && jnew < grid[0].size() && grid[inew][jnew] == 1) {
            area++;
            DFS(grid, inew, jnew, area); 
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxi = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    int area = 1;
                    DFS(grid, i, j, area);
                    maxi = max(maxi, area);
                }
            }
        }
        return maxi;
    }
};
