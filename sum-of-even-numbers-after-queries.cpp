// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> v;
        int sum = 0;
        for(auto x: nums)
            if(x % 2 == 0)
                sum += x; 
        for(int i = 0; i<queries.size(); i++){
            if(queries[i][0] % 2 == 0 && nums[queries[i][1]] % 2 == 0){
                nums[queries[i][1]] += queries[i][0];   
                sum += queries[i][0];
            }
            else if(queries[i][0] % 2 != 0 && nums[queries[i][1]] % 2 != 0){
                nums[queries[i][1]] += queries[i][0];
                sum += nums[queries[i][1]];
            }
            else{
                if(nums[queries[i][1]] % 2 == 0) sum -= nums[queries[i][1]];
                nums[queries[i][1]] += queries[i][0];
            }
            v.push_back(sum);
        }
        return v;
    }
};
