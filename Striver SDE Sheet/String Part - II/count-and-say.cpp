// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        string res = "1";
        while(--n){
            string temp = "";
            for(int i = 0; i<res.size(); i++){
                int count = 1;
                while((i + 1 < res.size()) && (res[i] == res[i + 1])){
                    count++;
                    i++;
                }
                temp += to_string(count) + res[i];
            }
            res = temp;
        }
        return res;
    }
};  
