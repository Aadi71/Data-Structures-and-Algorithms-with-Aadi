// https://leetcode.com/problems/rotting-oranges/

// Optimised and efficient approach

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid[0].size();
        int i = 0, j = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int time = 0;
        int a[] = {0, 0, -1, 1};
        int b[] = {-1, 1, 0, 0};
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++){
                    int inew = i + a[k];
                    int jnew = j + b[k];
                    if(inew >= 0 && jnew >= 0 && inew < row && jnew < col && grid[inew][jnew] == 1){
                        grid[inew][jnew] = 2;
                        q.push({inew, jnew});
                    }
                }
            }
            time++;
        }
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        if(time == 0) return 0;
        return time - 1;
    }
};



// Naive - First Approach
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid[0].size();
        int i = 0, j = 0;

        vector<vector<bool>> vis(row, vector<bool> (col, false));

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int n = q.size();
            bool change = false;

            while(n--){
                int i = q.front().first;
                int j = q.front().second;

                q.pop();
                if((i - 1) >= 0 && vis[i - 1][j] == false && grid[i - 1][j] == 1){
                    q.push({i-1, j});
                    grid[i - 1][j] = 2;
                    vis[i-1][j] = true;
                    change = true;
                } 
                if((i + 1) < row && vis[i + 1][j] == false && grid[i + 1][j] == 1){
                    q.push({i+1, j});
                    grid[i + 1][j] = 2;
                    vis[i+1][j] = true;
                    change = true;
                }
                if((j - 1) >= 0 && vis[i][j - 1] == false && grid[i][j - 1] == 1){
                    q.push({i, j - 1});
                    vis[i][j - 1] = true;
                    grid[i][j - 1] = 2;
                    change = true;
                }
                if((j + 1) < col && vis[i][j + 1] == false && grid[i][j + 1] == 1){
                    q.push({i, j + 1});
                    vis[i][j + 1] = true;
                    grid[i][j + 1] = 2;
                    change = true;
                }
            }
            if(change == true) time++;
        }
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return time;
    }
};
