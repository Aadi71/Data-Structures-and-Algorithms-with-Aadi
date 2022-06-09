// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i1 = 0;
        int i2 = numbers.size() - 1;
        
        vector<int> v;
        
        while(numbers[i1] + numbers[i2] != target){
            if(numbers[i1] + numbers[i2] > target) i2--;
            else i1++;
        }
        v.push_back(i1 + 1);
        v.push_back(i2 + 1);
        return v;
    }
};
