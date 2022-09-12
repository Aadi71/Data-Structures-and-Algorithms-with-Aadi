// https://leetcode.com/problems/bag-of-tokens/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int maximum = 0;
        int i = 0, j = tokens.size() - 1;
        while(i <= j){
            if(tokens[i] <= power){
                score++;
                power -= tokens[i];
                i++;
            }
            else if(score > 0){
                score--;
                power += tokens[j];
                j--;
            }
            else{
                return 0;
            }
            maximum = max(score, maximum);
        }
        return maximum;
    }
};
