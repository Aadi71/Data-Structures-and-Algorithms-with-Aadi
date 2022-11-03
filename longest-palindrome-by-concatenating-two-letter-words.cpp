// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> umap;
        for(auto i: words) umap[i]++;
        
        int ans = 0;
        bool central = false;
        
        for(auto i: umap){
            if(i.first[0] == i.first[1]){
                if(i.second % 2 == 0) ans += i.second;
                else{
                    ans += i.second - 1;
                    central = true;
                }
            }
            else if(i.first[0] < i.first[1] && umap.count({i.first[1], i.first[0]}))
                ans += 2 * min(i.second, umap[{i.first[1], i.first[0]}]);
        }
        if(central) ans++;
        return 2 * ans;
    }
};
