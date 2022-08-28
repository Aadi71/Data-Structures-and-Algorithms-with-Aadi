#include <iostream>
#include <set>
using namespace std;


int main(){
    cin.sync_with_stdio(false);
    int n; cin >> n;
    int arr[n]; 
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    long long sum = 0;
    for(int i = 1; i<n; i++){
        long long diff = arr[i] < arr[i - 1] ? arr[i - 1] - arr[i] : 0;
        sum += diff;
        arr[i] += diff;
    }
    cout << sum;
}
