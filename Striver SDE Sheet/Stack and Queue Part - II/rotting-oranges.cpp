// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){   
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int a[] = {0, 0, -1, 1};
        int b[] = {-1, 1, 0, 0};
        int time = 0;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++){
                    int inew = i + a[k];
                    int jnew = j + b[k];
                    if(inew >= 0 && jnew >= 0 && inew < m && jnew < n && grid[inew][jnew] == 1){
                        grid[inew][jnew] = 2;
                        q.push({inew, jnew});
                    }
                }
            }
            time++;
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time == 0 ? 0 : --time;
    }
};
