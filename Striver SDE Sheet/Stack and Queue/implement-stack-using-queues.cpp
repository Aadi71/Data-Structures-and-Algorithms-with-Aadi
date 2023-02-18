// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int> q;
    void push(int x) {
        q.push(x);
        for(int i = 0; i<q.size()-1; i++){   
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};
