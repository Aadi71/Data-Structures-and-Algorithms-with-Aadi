#include <iostream>
#include <set>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    int n; cin >> n;
    set<int> s;
    while(n--){
        int i; cin >> i;
        s.insert(i);
    }
    cout << s.size();
}
