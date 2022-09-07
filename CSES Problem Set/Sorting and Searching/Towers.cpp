#include <bits/stdc++.h>
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define rep(i,a,b) for(int i = a; i < b; i++)
#define vv vector<ll>
#define ll long long
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    multiset<int> m;
    multiset<int>::iterator it;
    fr(0, n){
        ll k; cin >> k;
        it = m.upper_bound(k);
        if(it != m.end()) m.erase(it);
        m.insert(k);
    }
    cout << m.size();
}
