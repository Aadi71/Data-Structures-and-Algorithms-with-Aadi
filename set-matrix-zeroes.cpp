// https://leetcode.com/problems/set-matrix-zeroes/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> v;
        
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    v.push_back({i, j});
                }
            }
        }
        for(int i = 0; i<v.size(); i++){
            for(int j = 0; j<v[i].size(); j++){
                cout<<v[i][j];
            }
        }
        int p = 0;
        while(p < v.size()){
            int i = v[p][0];
            int j = v[p][1];
            for(int k = 0; k<i; k++){
                matrix[k][j] = 0;
            }
            for(int k = i; k<matrix.size(); k++){
                matrix[k][j] = 0;
            }
            
            
            for(int k = 0; k<j; k++){
                matrix[i][k] = 0;
            }
            for(int k = j; k<matrix[i].size(); k++){
                matrix[i][k] = 0;
            }

            p++;
        }
        
        
    }
};
