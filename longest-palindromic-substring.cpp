// https://leetcode.com/problems/longest-palindromic-substring/


class Solution {
public:
    string longestPalindrome(string s) {

        string str = "";
        int m = 0;
        
        for(int i = 0; i<s.length(); i++){
            // For odd length
            int j = i;
            int k = i;
            while(j>=0 && k<s.length() && s[j] == s[k]){
                if(k - j + 1 > m){
                    m = k - j + 1;
                    str = s.substr(j, m);
                } 
                j--; k++;
            }
            
            // For even length
            j = i;
            k = i + 1;
            while(j>=0 && k<s.length() && s[j] == s[k]){
                if(k - j + 1 > m){
                    m = k - j + 1;
                    str = s.substr(j, m);
                } 
                j--; k++;
            }
            
        }
        return str;       
    }
};
