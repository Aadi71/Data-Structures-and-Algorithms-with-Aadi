// https://leetcode.com/problems/excel-sheet-column-number/


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        
        if(n == 1) return columnTitle[0] - 'A' + 1;
        
        int sum = 0;
        int p = 0;
        
        for(int i = n - 1; i>=0; i--){
            int pos = columnTitle[i] - 'A' + 1;
            sum += pos * pow(26, p);
            p++;
        }
        
        return sum;
    }
};  
