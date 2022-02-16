// Find the complexity of an algorithm using the Extended Master Theorem.

// The Recurrence relation is given in form of :

// T(n) = aT(n/b) + θ(nk(logn)p)

// The value of a, b, k, p will be given and find the complexity and the recurrence relation.


#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, k, p;
    cin>>a>>b>>k>>p;
    cout<<"T(n)="<<a<<"T(n/"<<b<<")+Theta(n^"<<k<<"(log_2^n)^"<<p<<")";
    cout<<endl;
    if(a>0 && b>1 &&k >=0){
        if(a > pow(b, k)) cout<<"Complexity=Theta(n^(log_"<<b<<"^"<<a<<"))";
        else if(a == pow(b, k)){
            if(p > -1) cout<<"Complexity=Theta(n^(log_"<<b<<"^"<<a<<")(log_"<<b<<"^n)^"<<p+1<<")";
            else if(p == -1) cout<<"Complexity=Theta(n^(log_"<<a<<"^"<<a<<"loglogn";
            else cout<<"Complexity=Theta(n^(log_"<<b<<"^"<<a<<"))";
        }    
        else{
            if(p >= 0) cout<<"Complexity=Theta(n^"<<k<<"(log_"<<a<<"^n)^"<<p<<")";
            else cout<<"Complexity=Theta(n^"<<k;
        }
    }
}
