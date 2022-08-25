// https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int i: nums) s.insert(i);
        return s.size()<3 ? *max_element(s.begin(), s.end()) : *next(s.begin(), s.size() - 3);
    }
};
