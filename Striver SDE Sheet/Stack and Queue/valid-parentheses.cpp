// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i<s.length(); i++){
            char temp = s[i];
            if(temp == '(' || temp == '{' || temp == '[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                int t = st.top();
                if((temp == ')' && t == '(') || (temp == ']' && t == '[') || (temp == '}' && t == '{')) st.pop();
                else return false; 
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
