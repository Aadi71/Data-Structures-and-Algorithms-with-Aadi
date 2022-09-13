// https://leetcode.com/problems/utf-8-validation/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = 0;
        int c1 = 1 << 7;
        int c2 = 1 << 6;
        for(int i = 0; i<data.size(); i++){
            if(n == 0){
                int c = 1 << 7;
                while((c & data[i]) != 0){
                    n += 1;
                    c = c >> 1;
                }
                if(n == 0) continue;
                if(n > 4 || n == 1) return false;
            }
            else
                if(!((data[i] & c1) != 0 && (c2 & data[i]) == 0)) return false;
            n--;
        }
        return n == 0;
    }
};
