#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> v(n + 1, 0);
    for(ll i = 1; i<=n; i++){
        int num; cin >> num;
        v[num] = i; 
    }
    ll sum = 1;
    for(ll i = 2; i<=n; i++)
        if(v[i-1] > v[i])
            sum++;
    cout << sum;
    return 0;
}
