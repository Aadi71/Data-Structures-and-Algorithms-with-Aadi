// https://leetcode.com/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
      
        // TC: O(nlogn)
        int sum = 0;
        vector<int> v = heights;
        sort(v.begin(), v.end());
        
        for(int i = 0; i<heights.size(); i++){
            if(heights[i] != v[i]) sum++;
        }
        return sum;
        
        // TC: O(n)
        vector<int> v(101, 0);
        int n = heights.size();
        for(int i = 0; i<n; i++) v[heights[i]]++;
        
        int i = 0, j = 0;
        int count = 0;
        while(i < 101){
            if(v[i] == 0) i++;
            else{
                if(i != heights[j]) count++;
                j++; v[i]--;
            }
        }
        return count;
    }
};
