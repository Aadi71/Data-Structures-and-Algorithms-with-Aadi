// https://leetcode.com/problems/container-with-most-water/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() - 1;
        
        int i = 0;
        int j = n;
        int area = 0;
        
        while(i<j){
            area = max((j - i) * min(height[i], height[j]), area);
            if(height[i] > height[j]) j--;
            else i++;
        }
        return area;
    }
};
