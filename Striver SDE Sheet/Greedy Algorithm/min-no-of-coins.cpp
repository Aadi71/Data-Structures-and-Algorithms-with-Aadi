// https://www.codingninjas.com/codestudio/problems/975277?

#include <bits/stdc++.h> 
using namespace std;

int findMinimumCoins(int amount){
    vector<int> arr = {1,2,5,10,20,50,100,500,1000};
    int j = arr.size() - 1;
    int ans = 0;
    while(amount){
        if(amount >= arr[j]){
            ans += amount / arr[j];
            amount = amount % arr[j];
        }
        j--;
    }
    return ans;
}
