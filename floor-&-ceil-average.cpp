/*
A scientist has collected the data (X) of a given experiment in a sorted fashion. He has a value V, and he wishes to compute the average of ceiling and floor values of V. Calculate the average if both values i.e., floor and ceiling of x are available. Otherwise, display the available value (floor or ceil). Use the concept of divide and conquer for the efficient implementation.

Hint:

A ceiling of V is the minimum number in X ≥ V.

Floor is the maximum number in X ≤ V.

Input:

5

1 3 7 9 12

4

Where,

First line enters the size of an array.

Second line takes the elements of the array.

Third line enters the number for which floor and ceil values to be calculated from array.

Output:

average of 4 is 5
*/

#include <iostream>
using namespace std;

int ceil(int nums[], int t, int n){
    int low = 0; int high = n - 1; int c = -1;
    while(low<=high){
        int mid = (high+low)/2;

        if(nums[mid] > t){
            c = nums[mid];
            high = mid - 1;
        }
        else if(nums[mid] < t) low = mid + 1;

        else{
            return nums[mid];
        }
    }

    return c;
}

int floor(int nums[], int t, int n){
    int low = 0; int high = n - 1; int c = -1;
    while(low<=high){
        int mid = (high+low)/2;

        if(nums[mid] < t){
            c = nums[mid];
            low = mid + 1;
            1 3 7 9 12
        }
        else if(nums[mid] > t) high = mid - 1;

        else{
            return nums[mid];
        }
    }

    return c;
}

int main(){
    int n; cin>>n;
    int arr[n];

    for(int i = 0; i<n;i++) cin>>arr[i];

    int t; cin>>t;
    cout<<ceil(arr, t, n)<<endl;
    cout<<floor(arr, t, n);



    return 0;
}
