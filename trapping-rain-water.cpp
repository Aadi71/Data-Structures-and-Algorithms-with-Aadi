//https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();
        
        if(n <= 2) return 0;
        
        int lmax = height[0];
        int rmax = height[n-1];
        
        int i = 0;
        int j = n-1;
        while(i<j){
            lmax = max(lmax, height[i]);
            rmax = max(rmax, height[j]);
            
            if(lmax > rmax){
                sum += rmax - height[j--];
            }
            else{
                sum += lmax - height[i++];
            }
        }   
        return sum;
    }
};
