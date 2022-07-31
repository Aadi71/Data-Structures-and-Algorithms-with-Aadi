// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        
        unordered_set<int> v1(nums1.begin(), nums1.end());
        unordered_set<int> :: iterator itr;
        unordered_set<int> v2(nums2.begin(), nums2.end());
        if(v1.size() < v2.size()){
            for (itr = v1.begin(); itr != v1.end(); itr++){
                if(v2.find(*itr) != v2.end()) v.push_back(*itr);
            }
        }
        else{
            for (itr = v2.begin(); itr != v2.end(); itr++){
                if(v1.find(*itr) != v1.end()) v.push_back(*itr);
            }
        }
        return v;
    }
};
