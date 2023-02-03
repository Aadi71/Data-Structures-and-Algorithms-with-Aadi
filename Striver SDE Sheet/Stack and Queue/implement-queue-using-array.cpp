// https://www.codingninjas.com/codestudio/problems/2099908?

#include <bits/stdc++.h> 
class Queue {
public:
    int *arr;
    int ptr;
    int i;
    Queue() {
        ptr = 0;
        i = 0;
        arr = new int[10000];
    }
    bool isEmpty() {
        return (ptr == i);
    }

    void enqueue(int data) {
        arr[ptr++] = data;
    }

    int dequeue() {
        if(ptr == i) return -1;
        return arr[i++];
    }

    int front() {
        if(ptr == i) return -1;
        return arr[i];
    }
};
