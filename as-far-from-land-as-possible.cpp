// https://leetcode.com/problems/as-far-from-land-as-possible/

// Optimized and Fast Approach
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) continue;
                grid[i][j] = 201;
                if(i > 0) grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
                if(j > 0) grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
            }
        }
        for(int i = n -1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 1) continue;
                if(i < n - 1) grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
                if(j < n - 1) grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);
                ans = max(grid[i][j], ans);
            }
        }
        return ans == 201 ? -1 : ans - 1;
    }
};




// BFS approach

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i - 1, j});
                    q.push({i + 1, j});
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                }
            }
        }
        int steps = 0;
        while(!q.empty()){
            int s = q.size();
            steps++;
            for(int k = 0; k<s; k++){
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0){
                    grid[i][j] = steps; 
                    q.push({i - 1, j});
                    q.push({i + 1, j});
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                }
            }
        }
        return steps == 1 ? -1 : steps - 1;
    }
};
