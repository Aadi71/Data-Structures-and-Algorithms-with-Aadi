// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        
        for(int i = 0; i<numRows; i++){
            vector<int> temp(i+1, 1);
            
            if(i >1){
                int k = 0;
                for(int j = 1; j<i; j++){
                    temp[j] = v[i-1][k++] + v[i-1][k];
                }
            }
            
            v.push_back(temp);
        }
        return v;
    }
};
