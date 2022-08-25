// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1, 0);
        vector<int> result;
        for(auto i: nums) 
            v[i]++;
        for(int i = 1; i <= n; i++)
            if(v[i] == 0)
                result.push_back(i);
        return result;
    }
};
