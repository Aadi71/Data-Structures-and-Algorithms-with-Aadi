// https://leetcode.com/problems/first-bad-version/

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n; 
        int mid;
        while(s<e){
            mid = s + (e-s) / 2;
            if(isBadVersion(mid)) e = mid;
            else s = mid + 1;
        }
        return s;
    }
};
