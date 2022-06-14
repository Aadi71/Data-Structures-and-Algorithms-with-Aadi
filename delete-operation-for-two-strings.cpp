// https://leetcode.com/problems/delete-operation-for-two-strings/


class Solution {
public:
    int lcs(string w1, string w2, int n1, int n2){
        int arr[n1 + 1][n2 + 1];
        
        for(int i = 0; i<=n1; i++){
            for(int j = 0; j<=n2; j++){
                if(i == 0 || j == 0) arr[i][j] = 0;
                else if(w1[i-1] == w2[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
                else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
        return arr[n1][n2];
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        int n = lcs(word1, word2, n1, n2);
        return(n1 + n2 - 2*n); 
    }
};
