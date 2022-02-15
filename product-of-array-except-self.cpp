// https://leetcode.com/problems/product-of-array-except-self/submissions/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> v;
        
        int temp = 1;
        for(int i = 0;i < nums.size(); i++) v.push_back(1);
        for(int i = 0; i< nums.size(); i++){
            v[i] = temp;
            temp = temp * nums[i];
        }
        
        temp = 1;
        for(int i = nums.size() - 1; i >=0; i--){
            v[i] = v[i] * temp;
            temp = temp * nums[i];
        }
        
        return v;
    }
};    


// My soultion, test cases are running, but giving time exceeded error at specific test cases
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//       vector <int> v;
//       int i = 0;
//         int prod = 1;
//         int j = 0;
//         while(i<nums.size()){
//             if(i == nums.size() - 1 && i != j){
//                 prod = prod * nums[i];
//                 i = 0;
//                 v.push_back(prod);
//                 j++;
//                 prod = 1;
//             }
//             else if(i==nums.size() - 1 && i==j){
//                 v.push_back(prod);
//                 break;
//             }
//             else if(i == j) i++;
//             else {
//                 prod = prod * nums[i];
//                 i++;
//             }
//         }
//         return v;
// }
// };
