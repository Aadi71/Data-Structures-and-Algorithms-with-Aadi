// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// Naive Approach: Time Complexity - O(mn)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0; 
        int j;
        while(i < haystack.size()){
            int k = i;
            j = 0;
            while(k < haystack.size() && j < needle.size()){
                if(haystack[k] != needle[j]) break;
                j++; k++;
            }
            if(j == needle.size()) return i;
            i++;
        }
        return -1;
    }
};

// KMP Algorithm
