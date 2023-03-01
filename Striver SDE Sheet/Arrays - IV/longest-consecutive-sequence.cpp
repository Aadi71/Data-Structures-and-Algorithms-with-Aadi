// https://leetcode.com/problems/longest-consecutive-sequence/

// Brute Force. Sorting. TC: O(NlogN)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int m = 0;
        if(nums.size() == 0) return 0;
        int temp = 1;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] == 1) temp ++;
            else{
                m = max(m, temp);
                temp = 1;
            }
        }
        m = max(m, temp);
        return m;
    }
};

// Optimized to TC: O(N) using hashsets.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> uset(nums.begin(), nums.end());
        int ans = 1;
        for(auto it: uset){
            if(uset.find(it - 1) != uset.end()) continue;
            int temp = 1;
            int check = it + 1;
            while(uset.find(check) != uset.end()){
                check++;
                temp++;
            }
            ans = ans > temp ? ans : temp; 
        }
        return ans;
    }
};
