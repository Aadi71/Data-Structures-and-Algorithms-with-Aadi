// https://leetcode.com/problems/valid-anagram/

// Fastest
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};

// Faster
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> count;
        for(int i = 0; i<t.length(); i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        for(auto x: count) if(x.second) return false;
        return true;
    }
};


// Fast
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
    
        int arr[26] = {0};
    
        for(int i = 0; i<s.length(); i++){
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for(int i = 0; i<26; i++) if(arr[i]) return false;
        return true;
    }
};
