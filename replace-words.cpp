// https://leetcode.com/problems/replace-words/

class TrieNode{
    public:
    bool word;
    TrieNode *children[26];
    TrieNode(){
        word = false;
        for(int i = 0; i<26; i++) children[i] = NULL;
    }
};

class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode *curr = root;
        for(int i = 0; i < word.size(); i++){
            int k = word[i] - 'a';
            if(curr -> children[k] == NULL) curr -> children[k] = new TrieNode();
            curr = curr -> children[k];
        }
        curr -> word = true;
    }
    string successor(string word){
        TrieNode* curr = root;
        string str = "";
        if(curr -> children[word[0] - 'a'] == NULL) return word;
        else{
            for(int i = 0; i<word.size(); i++){
                int k = word[i] - 'a';
                if(curr -> word == true) return str;
                if(curr -> children[k] == NULL) return word;
                str += word[i];
                curr = curr -> children[word[i] - 'a'];
            }
        }
        return str;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for(int i = 0; i < dictionary.size(); i++) t.insert(dictionary[i]);
        string ans = "";

        int i = 0; 
        while(i < sentence.size()){
            string temp = "";
            while(i < sentence.size() && sentence[i] != ' ') temp += sentence[i++];
            ans += t.successor(temp) + " ";
            i++;
        }
        ans.pop_back();
        return ans;
    }
};
