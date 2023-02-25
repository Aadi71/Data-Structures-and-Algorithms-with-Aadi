// https://leetcode.com/problems/majority-element/

// Brute Force, O(N) Space Complexity using maps.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int i = 0; i<nums.size(); i++){
            umap[nums[i]]++;
        }
        int maxi = 0;
        int ans = nums[0];

        for(auto i: umap){
            if(i.second > maxi){
                maxi = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};

// Boyer-Moore Algorithm: Optimized to O(1) Space Complexity
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(c == 0) ans = nums[i];
            if(ans == nums[i]) c++;
            else c--;
        }
        return ans;
    }
};
