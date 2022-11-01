// https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    int findDFS(int row, int col, vector<vector<int>>& grid, int n){
        if(row == grid.size()) return col;
        int newCol = col + grid[row][col];
        if(newCol < 0 || newCol > n - 1 || grid[row][col] != grid[row][newCol]) return -1;
        return findDFS(row + 1, newCol, grid, n);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> res(n, 0);
        for(int i = 0; i<n; i++)
            res[i] = findDFS(0, i, grid, n);
        return res;
    }
};
