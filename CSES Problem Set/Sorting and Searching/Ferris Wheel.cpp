#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int solve(vector<int> &a, int m){
    int count = 0;
    int sum = 0;
    int n = a.size() - 1;
    for(int j = n, i = 0; j >= i; j--){
        if(a[i] + a[j] <= m) i++;
        count++;
    }
    return count;
}
 
int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for(int i = 0; i<n; i++) cin >> v[i];
 
    sort(v.begin(), v.end());
 
    cout << solve(v, m);
}
