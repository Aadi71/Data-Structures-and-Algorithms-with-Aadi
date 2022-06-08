// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char temp = st.top();
                if((s[i] == ']' && temp == '[') || (s[i] == '}' && temp == '{') || (s[i] == ')' && temp == '(')) st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
