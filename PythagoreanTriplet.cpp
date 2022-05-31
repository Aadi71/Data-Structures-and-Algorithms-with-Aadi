#include<iostream>
using namespace std;

int pythagoreanTriplet(int x, int y, int z){
    int a, b, c;
    a = max(x, max(y, z));
    if(a == x){
        b = y;
        c = z;
    }
    else if(a == y){
        b = x;
        c = z;
    }
    else{
        b = x;
        c = y;
    }
    if(a * a == b * b + c * c) return true;
    return false;
}
int main(){
    cout<<pythagoreanTriplet(5,4,3);
}
