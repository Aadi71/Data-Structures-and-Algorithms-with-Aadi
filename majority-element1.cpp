// https://leetcode.com/problems/majority-element/submissions/

// Solution-1 Without using Maps
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int freq = 0;
        int max = nums[0];
        for(int i = 0; i<nums.size();i++){
            if(nums[i] == max) 
                freq++;
            else if(nums[i] != max)
                freq--;
            
            if(freq == 0){
                max = nums[i];
                freq = 1;
            }
        }
        return max;
    }
};


// Using Divide and Conquer Approach

#include <iostream>
using namespace std;

int count(int arr[], int c, int i, int j){
    int res = 0;
    for(int k = i; k <=j;k++) if(arr[k] == c) res++;
    return res;
}

int getMajority(int arr[], int i, int j){
    if(i==j) return arr[i];
    
    int m = (i+j) / 2;
    int left = getMajority(arr, i, m);
    int right = getMajority(arr, m+1, j);

    if(left==right) return left;

    return count(arr, left, i, m) > count(arr, right, m+1, j) ? left : right; 
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    
    cout<<"The number "<<getMajority(arr, 0, n-1)<<" appears more than half of the time";

}
