#include <iostream>
#include <set>
using namespace std;


int main(){
    cin.sync_with_stdio(false);
    string dna;
    cin >> dna;
    int res = 1, c = 1;
    for(int i = 1; i<dna.length(); i++){
        if(dna[i] == dna[i - 1]) c++;
        else{
            res = res > c ? res : c;
            c = 1; 
        }
    }
    res = res > c ? res : c;
    cout<<res;
}
