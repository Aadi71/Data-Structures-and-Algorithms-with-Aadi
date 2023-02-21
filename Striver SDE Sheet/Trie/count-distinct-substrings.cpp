// https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292

class TrieNode{
    public:
    TrieNode *children[26];
    TrieNode(){
        for(int i = 0; i<26; i++) children[i] = NULL;
    }
};

class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode();
    }
    int insert(string &word, int start){
        TrieNode *curr = root;
        int count = 0;
        for(int i = start; i<word.size(); i++){
            int k = word[i] - 'a';
            if(curr -> children[k] == NULL){
                curr -> children[k] = new TrieNode();
                count++;
            }
            curr = curr -> children[k];
        }
        return count;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie t;
    int sum = 0;
    for(int i = 0; i<s.size(); i++){
        sum += t.insert(s, i);
    }
    return ++sum;
}
