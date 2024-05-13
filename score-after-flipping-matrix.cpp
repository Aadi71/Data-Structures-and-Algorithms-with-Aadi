// https://leetcode.com/problems/score-after-flipping-matrix/description/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++)
            if (grid[i][0] == 0)
                for(int j = 0; j < n; j++)
                    grid[i][j] = grid[i][j] == 0 ? 1 : 0;

        for(int j = 1; j < n; j++) {
            int zeroCount = 0;
            for(int i = 0; i < m; i++)
                if (grid[i][j] == 0) zeroCount++;
            if (zeroCount > m / 2)
                for(int i = 0; i < m; i++)
                    grid[i][j] = grid[i][j] == 0 ? 1 : 0;
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            int power = 0;
            for(int j = n - 1; j >= 0; j--) {
                ans += grid[i][j] * pow(2, power);
                power++;
            }
        }
        return ans;
    }
};
