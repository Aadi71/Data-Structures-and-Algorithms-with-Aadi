https://leetcode.com/problems/long-pressed-name/


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        for(int i = 0; i < typed.length(); i++){
            if(name[j] == typed[i]){
                j++;
            }
            else if(j == 0)return false;
            else if(j > 0 && name[j - 1] != typed[i]) return false;
        }
        return j == name.length();
        
    }
};
