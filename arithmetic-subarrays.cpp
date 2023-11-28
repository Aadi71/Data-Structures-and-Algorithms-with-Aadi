// https://leetcode.com/problems/arithmetic-subarrays/

// Brute force. TC: O(m^2logm + m^2)
class Solution {
public:
    bool arithmetic_check(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int d = nums[1] - nums[0];
        for(int i = 1; i < nums.size() - 1; i++) 
            if(nums[i + 1] - nums[i] != d) 
                return false;
        
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;
        for(int i = 0; i < m; i++) {
            vector<int> temp;
            for(int j = l[i]; j <= r[i]; j++)
                temp.push_back(nums[j]);
            ans.push_back(arithmetic_check(temp));
        }
        return ans;
    }
};


// rather than sorting, finding each occurence of element. TC: O(m^2)

class Solution {
public:
    bool arithmetic_check(vector<int> nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = nums.size();
        unordered_set<int> uset;
        for(int i = 0; i < n; i++){
            maxi = maxi > nums[i] ? maxi : nums[i];
            mini = mini > nums[i] ? nums[i] : mini;
            uset.insert(nums[i]);
        }
        if((maxi - mini) % (n - 1) != 0) return false;
        int d = (maxi - mini) / (n - 1);
        int curr = mini + d;
        while(curr < maxi) {
            if(uset.find(curr) == uset.end()) return false;
            curr += d;
        }
        
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;
        for(int i = 0; i < m; i++) {
            vector<int> temp;
            for(int j = l[i]; j <= r[i]; j++)
                temp.push_back(nums[j]);
            ans.push_back(arithmetic_check(temp));
        }
        return ans;
    }
};
