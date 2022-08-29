#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    if(n == 1) cout << 1;
    else if(n <= 3) cout << "NO SOLUTION";
    else{
        for(int i = 2; i<=n; i+=2) cout << i << " ";
        for(int i = 1; i<=n; i+=2) cout << i << " ";
    }
}
int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    solve(n);
}
