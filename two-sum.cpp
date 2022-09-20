// https://leetcode.com/problems/two-sum/

// Approach 1
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


// Approach 2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i = 0; i<nums.size() - 1; i++){
            int temp = target;
                temp -= nums[i];
                for(int j = i + 1; j < nums.size(); j++){
                    if(temp == nums[j]){
                        v.push_back(i);
                        v.push_back(j);
                        return v;
                    }
                }
        }
        return v;
    }
};
