#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll sum = n * (n + 1) / 2;
    if(sum % 2 == 1){
        cout << "NO";
        return 0;  
    }
    else{
        ll ans = sum / 2;
        vector<ll> a;
        vector<ll> b;
        for(int i = n; i>= 1; i--){
            if(i <= ans){
                a.push_back(i);
                ans -= i;
            }
            else b.push_back(i);
        }
        cout << "YES\n" << a.size() << "\n";
        for(int i = 0; i<a.size(); i++) cout << a[i] << " ";
        cout << "\n" << b.size() << "\n";
        for(int i = 0; i<b.size(); i++) cout << b[i] << " ";
    }   
}
