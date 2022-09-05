#include <bits/stdc++.h>
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
using namespace std;
typedef long long int ll;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x; cin >> n >> x;
    vector<ll> coin(n, 0);
    fr(0, n) cin >> coin[i];
    vector<ll> sum(x + 1, 0);
    sum[0] = 1;
    for(ll i = 1; i<= x; i++){
        for(ll val: coin){
            if(val <= i)
                sum[i] = (sum[i] + sum[i - val]) % mod;
        }
    }
    cout << sum[x];
}
