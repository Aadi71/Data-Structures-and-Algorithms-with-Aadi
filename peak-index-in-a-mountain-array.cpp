https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
   
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1; int end = arr.size() - 2;
        while(start <= end){
            int mid = (start + (end-start)/2);
            
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;
            
            if(arr[mid - 1] > arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
};
