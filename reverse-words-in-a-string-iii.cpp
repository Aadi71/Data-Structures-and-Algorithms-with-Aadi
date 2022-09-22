// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverse(string s){
        int i = 0, j = s.length() - 1;
        while(i < j)
            swap(s[i++], s[j--]);
        return s;
    }
    string reverseWords(string s) {
        string str = "";
        for(int i = 0; i<s.length(); i++){
            string temp = "";
            while(i < s.length() && s[i] != ' ' && i != s.length())
                temp += s[i++];
            str += reverse(temp) + " ";
        }
        return str.substr(0, str.length() - 1);
    }
};
