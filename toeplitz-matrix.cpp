// https://leetcode.com/problems/toeplitz-matrix/


// Optimal Solution
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(i > 0 && j > 0 && matrix[i-1][j-1] != matrix[i][j]) return false;
            }
        }
        return true;
    }
};

// My first brute force
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        cout << row << " " << col << "\n";
        int a, b;
        for(int i = 0; i<row; i++){
            a = i, b = 0;
            while(a < row && b < col){
                cout << a << " " << b << "\n";
                if(matrix[a][b] != matrix[i][0]) return false;
                a++; b++;
            }
        }   
        for(int j = 0; j<col; j++){
            a = 0, b = j;
            while(a < row && b < col){
                cout << a << " " << b << "\n";
                if(matrix[a][b] != matrix[0][j]) return false;
                a++; b++;
            }
        }
        return true;
    }
};
