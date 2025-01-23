// https://leetcode.com/problems/count-servers-that-communicate/

// TC: O(m*n) SC: O(m+n)

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int totalServers = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowsServer(m, 0);
        vector<int> colsServer(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    rowsServer[i]++;
                    colsServer[j]++;
                    totalServers++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && rowsServer[i] == 1 && colsServer[j] == 1)
                    totalServers--;
            }
        }
        return totalServers;
    }
};
