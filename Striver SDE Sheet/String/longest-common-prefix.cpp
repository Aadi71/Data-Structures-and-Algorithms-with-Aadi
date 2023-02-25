// https://leetcode.com/problems/longest-common-prefix/

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = "";
        for(int i = 0; i < strs[0].length(); i++){
            for(int j = 0; j < strs.size(); j++) if(strs[0][i] != strs[j][i]) return temp;
            temp += strs[0][i];
        }
        return temp;
    }
};

// Just for fun, without taking temp variable
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].length(); i++){
            for(int j = 0; j < strs.size(); j++) if(strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
        }
        return strs[0];
    }
};
