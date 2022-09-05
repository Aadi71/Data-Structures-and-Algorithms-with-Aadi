#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> sum(n + 1, 0);
    sum[0] = 1;
    const unsigned int M = 1000000007;
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=6; j++){
            if(j > i) break;
            sum[i] += sum[i - j] % M;
        }
    }
    cout << sum[n] % M;
}
