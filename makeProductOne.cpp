// https://practice.geeksforgeeks.org/problems/minimum-steps-to-make-product-equal-to-one/1

class Solution {
  public:
    int makeProductOne(int arr[], int N) {
        // code here
        int neg = 0;
        int zeroes = 0;
        int pos = 0;
        int flag = 1;
        for(int i = 0; i<N; i++){
            if(arr[i] < 0){
                flag = flag * (arr[i] / abs(arr[i]));
                neg += (-1 - arr[i]);
            }
            else if(arr[i] == 0) zeroes++;
            else pos += arr[i] - 1;
        }
        int ans = 0;
        if(flag != -1) ans = neg + zeroes + pos;
        else{
            if(zeroes > 0) ans = neg + zeroes + pos;
            else ans = neg + zeroes + pos + 2;
        }
        return ans;
    }
};
