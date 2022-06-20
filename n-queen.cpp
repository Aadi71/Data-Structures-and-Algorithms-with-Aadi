#include<bits/stdc++.h>
#define n 8

using namespace std;

void printSolution(int board[n][n]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int board[n][n], int row, int col){
    int i, j;

    for(i = 0; i<col; i++)
        if(board[row][i])
            return false;

    for(i = row, j = col; i>=0 && j>=0; i--, j--)
        if(board[i][j])
            return false;

    for(i = row, j = col; j>=0 && i<n; i++, j--)
        if(board[i][j])
            return false;

    return true;
}


bool solveNQUtil(int board[n][n], int col){
    if(col>=n) return true;

    for(int i = 0; i<n; i++){
        if(isSafe(board, i, col)){
            board[i][col] = 1;

        if(solveNQUtil(board, col+1)) return true;

        board[i][col] = 0;
        }
    }
    return false;
}   



int main(){
    // int n;
    // cout<<"Enter Dimension of matrix: ";
    // cin>>n;
    // cout<<endl;

    int board[n][n] = {
        {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}
    };

    if(!solveNQUtil(board, 0)){
        cout<<"Solution doesn't exist"<<endl;
        return 0;
    }
    printSolution(board);
    return 0;
    
}
