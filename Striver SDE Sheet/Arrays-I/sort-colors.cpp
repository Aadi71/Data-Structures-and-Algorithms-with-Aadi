// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0, b = 0, c = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0) a++;
            else if(nums[i] == 1) b++;
            else c++;
        } 
        for(int i = 0; i<a; i++) nums[i] = 0;
        for(int i = a; i<a + b; i++) nums[i] = 1;
        for(int i = a + b; i<a + b + c; i++) nums[i] = 2;
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0, b = 0, c = nums.size() - 1;
        while(b <= c){
            switch(nums[b]){
                case 0: swap(nums[a++], nums[b++]); break;
                case 1: b++; break;
                case 2: swap(nums[b], nums[c--]); break;
            }
        }
    }
};
