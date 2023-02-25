// https://leetcode.com/problems/majority-element-ii/

// Brute Force using maps, linear time and linear space complexity
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++) umap[nums[i]]++;
        vector<int> ans;
        for(auto it: umap) if(it.second > nums.size() / 3) ans.push_back(it.first);
        return ans;
    }
};


// Extended Boyer-Moore Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            if(a == nums[i]) c1++;
            else if(b == nums[i]) c2++;
            else if(c1 == 0) {
                a = nums[i];
                c1++;
            }
            else if(c2 == 0) {
                b = nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            } 
        }
        c1 = 0;
        c2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == a) c1++;
            else if(nums[i] == b) c2++;
        }
        if(c1 > n / 3 && c2 > n / 3) return {a, b};
        else if (c1 > n / 3) return {a};
        else if(c2 > n / 3) return {b};
        else return {};
    }
};
