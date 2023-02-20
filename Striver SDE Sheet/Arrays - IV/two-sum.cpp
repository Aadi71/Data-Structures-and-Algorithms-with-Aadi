// https://leetcode.com/problems/two-sum/

// One-Pass Unordered Map(Hash) Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ind;
        for (int i = 0; i < nums.size(); i++) {
            if (ind.find(target - nums[i]) != ind.end())
                return {ind[target - nums[i]], i};
            ind[nums[i]] = i;
        }
        return {};
    }
};
