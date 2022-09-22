// https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int a = 0, b = 0;
        if(r * c != (mat.size() * mat[0].size())) return mat;
        vector<vector<int>> v(r, vector<int> (c, 0));
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[i].size(); j++){
                if(b < c) v[a][b++] = mat[i][j];
                else{
                    a++;
                    b = 0;
                    v[a][b++] = mat[i][j];
                }
            }
        }
        return v;
    }
};
