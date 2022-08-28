#include <iostream>
using namespace std;

void solve(long long int n){
    while(n != 1){
        cout << n << " ";
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
    cout << 1;
}

int main(){
    cin.sync_with_stdio(false);
    long long int n; cin >> n;
    solve(n);
    return 0;
}
