#include <iostream>
#include <set>
using namespace std;
 
 
int main(){
    cin.sync_with_stdio(false);
    int n; cin>>n;
    int x = 0;
    for(int i = 1; i<=n; i++) x ^= i;
    for(int j = 0; j < n-1; j++){
        int i; cin>>i;
        x ^= i;
    }
    cout << x;
}
