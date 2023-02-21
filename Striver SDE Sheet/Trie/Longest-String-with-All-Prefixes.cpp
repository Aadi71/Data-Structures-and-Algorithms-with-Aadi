// https://www.codingninjas.com/codestudio/problems/complete-string_2687860

#include <bits/stdc++.h> 
using namespace std;
class TrieNode{
    public:
    bool word;
    TrieNode *children[26];
    TrieNode(){
        word = 0;
        for(int i = 0; i<26; i++) children[i] = NULL;
    }
};

class Trie{
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string &word){
        TrieNode *curr = root;
        for(int i = 0; i<word.size(); i++){
            int k = word[i] - 'a';
            if(curr -> children[k] == NULL) curr -> children[k] = new TrieNode();
            curr = curr -> children[k];
        }
        curr -> word = true;
    }

    bool checkComplete(string &word){
        TrieNode *curr = root;
        int count = 0;
        for(int i = 0; i<word.size(); i++){
            int k = word[i] - 'a';
            if(curr -> children[k] == NULL) return false;
            curr = curr -> children[k];
            if(curr -> word == false) return false;
        }
        return curr -> word;
    }
};

string completeString(int n, vector<string> &a){
    Trie t;
    for(int i = 0; i<n; i++){
        t.insert(a[i]);
    }
    string ans = "";
    for(int i = 0; i<n; i++){
        if(t.checkComplete(a[i])){
            if(a[i].length() > ans.length()) ans = a[i];
            else if(a[i].length() == ans.length()) ans = ans < a[i] ? ans : a[i];
        }
    }
    if(ans == "") return "None";
    return ans;
}
