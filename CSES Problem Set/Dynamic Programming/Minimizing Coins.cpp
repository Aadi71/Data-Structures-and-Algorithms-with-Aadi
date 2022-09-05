#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x; cin >> n >> x;
    vector<ll> coins(n, 0);
    for(int i = 0; i<n; i++) cin >> coins[i];
    vector<ll> num(x + 1, x + 1);
    num[0] = 0;
    for(int i = 1; i<=x; i++){
        for(int j = 0; j<n; j++){
            if(i - coins[j] >= 0) num[i] = min(num[i], 1 + num[i - coins[j]]);
        }
    }
    if(num[x] == x + 1) cout << -1;
    else cout << num[x];
    return 0;
}
