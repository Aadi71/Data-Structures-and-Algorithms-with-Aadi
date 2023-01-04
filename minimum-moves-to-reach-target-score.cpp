// https://leetcode.com/problems/minimum-moves-to-reach-target-score/

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while(maxDoubles > 0 && target > 1){
            if(target % 2 == 0){
                target /= 2;
                maxDoubles--;
            }
            else target--;
            ans++;
        }
        return ans + (target - 1);
    }
};
