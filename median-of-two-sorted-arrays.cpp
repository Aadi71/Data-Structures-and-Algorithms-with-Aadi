// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <double> final;
        int b = 0;int c = 0;
        while(b < nums1.size() && c < nums2.size()){
            if(nums1[b] < nums2[c]){
                final.push_back(nums1[b]);
                b++;
            } 
            else{
                final.push_back(nums2[c]);
                c++;
            }
        }
        while(b < nums1.size()){
            final.push_back(nums1[b]);
            b++;
        }
        while(c < nums2.size()){
            final.push_back(nums2[c]);
            c++;
        }
        
        int a = final.size();
        double med;
        if(a % 2 == 0) med = (final[a/2] + final[a/2 - 1]) / 2;
        else med = final[a/2];
        
        return med;
    }
};
