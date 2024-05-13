// https://leetcode.com/problems/score-after-flipping-matrix/description/

// Logic: There are only two rules that you need to know in this problem. If the first number in the row is 0, flip the row. If the count of 0 in the col is greater than the count of 1, flip the col.
// why? because "1000..." is always larger than "0111...". No matter how many '1' you have after a leading '0', a leading '1' is always a better choice. The rest of the algorithm is just aiming for as much '1' as possible on every bit.

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
