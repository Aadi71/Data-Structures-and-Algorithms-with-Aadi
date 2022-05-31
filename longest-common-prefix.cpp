//https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str;
        int n = strs.size();
        
        int i = 0;
        for(int i = 0; i<strs[0].size(); i++){
            char temp = strs[0][i];
            for(int j = 0; j<n; j++){
                if(temp != strs[j][i]) return str;
            }
            str += strs[0][i]; 
        }
        return str;
    }
};
