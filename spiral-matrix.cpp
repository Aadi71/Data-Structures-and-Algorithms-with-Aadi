// https://leetcode.com/problems/spiral-matrix/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;
        
        int row_start = 0;
        int row_end = matrix.size()-1;
        
        int col_start = 0;
        int col_end = matrix[0].size()-1;
        
        while(result.size() != matrix.size()*matrix[0].size()){
            for(int row = col_start; row<=col_end; row++){
                result.push_back(matrix[row_start][row]);
            }
            row_start++;
            
            if(result.size() == matrix.size()*matrix[0].size()) break;
            
            for(int col = row_start; col<=row_end; col++){
                result.push_back(matrix[col][col_end]);
            }
            col_end--;
            
            if(result.size() == matrix.size()*matrix[0].size()) break;
            
            for(int row = col_end; row>=col_start; row--){
                result.push_back(matrix[row_end][row]);
            }
            row_end--;
            
            if(result.size() == matrix.size()*matrix[0].size()) break;
            
            for(int col = row_end; col>=row_start; col--){
                result.push_back(matrix[col][col_start]);
            }
            col_start++;
            
            if(result.size() == matrix.size()*matrix[0].size()) break;
        }
        return result;
    }
};
