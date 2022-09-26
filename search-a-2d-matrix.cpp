// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = 0;
        int col = matrix[0].size();
        while( i < matrix.size() && matrix[i][col - 1] < target) i++;
        while(j < col && i < matrix.size()){
            if(matrix[i][j] == target) return true;
            j++;
        }
        return false;
    }
};
