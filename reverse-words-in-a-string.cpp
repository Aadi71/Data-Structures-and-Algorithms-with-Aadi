// https://leetcode.com/problems/reverse-words-in-a-string/

// Solution using Stack and O(N) space for the stack
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<string> st;
        int i = 0;
        while(i < s.length()){
            if(s[i] == ' ') i++;
            else{
                string temp = "";
                while(i < s.length() && s[i] != ' '){
                    temp += s[i++];
                }
                st.push(temp);
            }
        }
        while(!st.empty()){
            if(st.size() == 1) ans += st.top();
            else ans += st.top() + " ";
            st.pop();
        }
        return ans;
    }
};

// Optimized in constant space O(1) - Space Complexity
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.length() - 1;
        while(i >= 0){
            while(i >= 0 && s[i] == ' ') i--;
            int j = i;
            if(i < 0) break;
            while(i >= 0 && s[i] != ' ') i--;
            if(ans == "") ans += s.substr(i + 1, j - i);
            else ans += " " + s.substr(i + 1, j - i);
        }
        return ans;
    }
};
