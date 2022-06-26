// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v;
        
        for(int i = 0; i<=rowIndex; i++){
            vector<int> temp(i+1, 1);
            
            if(i >1){
                int k = 0;
                for(int j = 1; j<i; j++){
                    temp[j] = v[i-1][k++] + v[i-1][k];
                }
            }
            
            v.push_back(temp);
            if(i == rowIndex) return v[i];
        }
        return v[rowIndex];
    }
};
