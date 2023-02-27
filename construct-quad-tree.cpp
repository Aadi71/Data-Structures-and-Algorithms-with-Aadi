// https://leetcode.com/problems/construct-quad-tree/

class Solution {
public:
    Node* quadTree(vector<vector<int>>& grid, int row_start, int row_end, int col_start, int col_end){
        if(row_start > row_end || col_start > col_end) return NULL;
        bool flag = true;
        int check = grid[row_start][col_start];
        for(int i = row_start; i <= row_end; i++){
            for(int j = col_start; j <= col_end; j++){
                if(check != grid[i][j]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) return new Node(check, true);

        int row_mid = (row_start + row_end) / 2;
        int col_mid = (col_start + col_end) / 2;
        Node* topLeft = quadTree(grid, row_start, row_mid, col_start, col_mid);
        Node* topRight = quadTree(grid, row_start, row_mid, col_mid + 1, col_end); 
        Node* bottomLeft = quadTree(grid, row_mid + 1, row_end, col_start, col_mid);
        Node* bottomRight = quadTree(grid, row_mid + 1, row_end, col_mid + 1, col_end);
        return new Node(check, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return quadTree(grid, 0, n - 1, 0, n - 1);
    }
};
