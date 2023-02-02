// https://leetcode.com/problems/next-greater-element-i/

// Brute Force
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i<nums1.size(); i++){
            int val = -1;
            for(int j = 0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    int k = j;
                    while(k < nums2.size()){
                        if(nums2[k] > nums2[j]){
                            val = nums2[k];
                            break;
                        }
                        k++;
                    }
                    break;
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};

// Monotonic Stacks
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> umap;
        for(int i = nums2.size() - 1; i>=0; i--){
            while(!st.empty() && nums2[i] > st.top()) st.pop();
            if(st.empty()) umap[nums2[i]] = -1;
            else umap[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for(int i = 0; i<nums1.size(); i++) res.push_back(umap[nums1[i]]);
        return res;
    }
};
