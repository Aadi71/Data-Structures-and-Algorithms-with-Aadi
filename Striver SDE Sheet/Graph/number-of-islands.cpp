// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        int a[] = {-1, 1, 0, 0};
        int b[] = {0, 0, -1, 1};
        grid[i][j] = '2';
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int k = 0; k<4; k++){
                int inew = i + a[k];
                int jnew = j + b[k];
                if(inew >= 0 && jnew >= 0 && inew < grid.size() && jnew < grid[0].size() && grid[inew][jnew] == '1') {
                    grid[inew][jnew] = '2';
                    q.push({inew, jnew});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    bfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
