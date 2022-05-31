// To print a pascal Triangle, for ex: of n = 5, then output pattern will be:
// 1 
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

#include<iostream>
using namespace std;

int factorial(int n){
    int s = 1;
    if(n == 0 || n ==1) return s;
    for(int i = n; i>=1; i--){
        s *= i;
    }
    return s;
}

int pascalTriangle(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j < i+1; j++){
            cout<<factorial(i) / (factorial(j) * factorial(i-j))<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    pascalTriangle(n);
}
