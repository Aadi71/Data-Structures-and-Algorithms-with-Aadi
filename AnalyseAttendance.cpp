#include<iostream>
#include<cstdio>
using namespace std;

void search(int arr[], int low, int high)
{
 
    // Base cases
    if (low > high)
        return;
 
    if (low == high) {
        cout <<arr[low];
        return;
    }
 
    // Find the middle point
    int mid = (low + high) / 2;
 
    // If mid is even and element next to mid is
    // same as mid, then output element lies on
    // right side, else on left side
    if (mid % 2 == 0) {
        if (arr[mid] == arr[mid + 1])
            search(arr, mid + 2, high);
        else
            search(arr, low, mid);
    }
 
    // If mid is odd
    else {
        if (arr[mid] == arr[mid - 1])
            search(arr, mid + 1, high);
        else
            search(arr, low, mid - 1);
    }
}

int main()
{
    int arr[19];
    for(int i = 0; i<19;i++) cin>>arr[i];
    
    search(arr, 0, 19);   
    
    return 0;
}
