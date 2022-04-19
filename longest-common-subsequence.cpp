// https://leetcode.com/problems/longest-common-subsequence/

// This solution that I have done is using the concept of Dynamic Programming by creating a 2D array.


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.length();
        int b = text2.length();
        
        int arr[a+1][b+1];
        int i, j;
        for(i = 0; i<=a; i++){
            for(j = 0; j<=b; j++){
                if(i == 0 || j == 0) arr[i][j] = 0;    
            }
        }
        
        for(i = 1; i<=a; i++){
            for(j = 1; j<=b; j++){
                if(text1[i-1] == text2[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
                else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
        return arr[a][b];
    }
};
