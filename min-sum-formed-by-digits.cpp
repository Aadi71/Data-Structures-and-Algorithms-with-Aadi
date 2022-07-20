// https://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits3551/


class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr, arr + n);
        long long int a = 0, b = 0, base = 1;
        for(int i = n-1; i >= 0; i--){
            a += (arr[i--] * base);
            if(i < 0) break;
            b += (arr[i] * base);
            base *= 10;
        }
        
        return a + b;
    }
};
