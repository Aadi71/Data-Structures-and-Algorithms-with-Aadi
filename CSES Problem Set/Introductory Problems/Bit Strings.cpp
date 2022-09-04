#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    const unsigned int M = 1000000007;
    ll ans = 1;
    for(ll i = 0; i<n; i++){
        ans *= 2;
        ans %= M;
    }
    cout << ans;
}
