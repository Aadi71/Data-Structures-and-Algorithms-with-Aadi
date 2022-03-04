// John is the Ticket Collector at the New Jersey Station. During the pandemic time, majority of the trains were not running therefore, tracking the platform number was not required. But as the number of COVID cases are declining, the government decided to run all the trains in full-fledged manner to curb the losses faced by the railway organisation. John is given a task to find the number of minimum platforms required to avoid delay in the train arrival. He has a schedule of all the trains having their arrival and departure time. Help John to design an algorithm to complete his task efficiently with O(nlogn) time complexity.
// Input:
// Trains arrival = {2.00, 2.10, 3.00, 3.20, 3.50, 5.00}
// Trains departure = {2.30, 3.40, 3.20, 4.30, 4.00, 5.20}
// Output:
// The minimum platforms needed is 2
// The idea is to merge the arrival and departure times of trains and consider them in sorted order. Maintain a counter to count the total number of trains present at the station at any point. The counter also represents the total number of platforms needed at that time.

//     If the train is scheduled to arrive next, increase the counter by one and update the minimum platforms needed if the count is more than the minimum platforms needed so far.
//     If the train is scheduled to depart next, decrease the counter by 1.
//     One special case needs to be handled – when two trains are scheduled to arrive and depart simultaneously, depart the train first.



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    float arr[n];
    float dept[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    for(int i = 0; i<n; i++) cin>>dept[i];
    
    sort(arr, arr + n);    
    sort(dept, dept + n);    
    
    int plat = 0;
    int result = 0;
    int i = 0, j = 0;
    while(i < n && j < n){
        if(arr[i] < dept[j]){
            plat++;
            i++;
        }
        else{
            plat--;
            j++;
        }
        
        if(plat > result) result = plat;
    }
    
    cout<<result<<endl;
    return 0;
}
