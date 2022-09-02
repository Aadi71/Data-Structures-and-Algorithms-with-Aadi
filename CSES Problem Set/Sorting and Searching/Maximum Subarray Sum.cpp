#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i<n; i++) cin >> v[i];
    // Kadane's Algorithm
    ll ans = LLONG_MIN;
    ll temp = 0;
    for(int i = 0; i<n; i++){
        temp += v[i];
        if(ans < temp) ans = temp;
        if(temp < 0) temp = 0;
    }
    cout << ans;
}
