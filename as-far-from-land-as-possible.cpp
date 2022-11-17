// https://leetcode.com/problems/as-far-from-land-as-possible/

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
