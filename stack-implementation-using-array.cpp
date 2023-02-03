// https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209?

#include <bits/stdc++.h> 
using namespace std;
class Stack {
    
public:
    int j;
    int *arr; 
    int cap;
    Stack(int capacity) {
        arr = new int[capacity];
        j = -1;
        cap = capacity;
    }

    void push(int num) {
        if(j != cap - 1) arr[++j] = num;
    }

    int pop() {
        if(j >= 0) {
            j--;
            return arr[j + 1];
        }
        return -1;
    }
    
    int top() {
        if(j >= 0) return arr[j];
        else return -1;
    }
    
    int isEmpty() {
        return (j == -1);
    }
    
    int isFull() {
        return (j == cap - 1);
    }
    
};
