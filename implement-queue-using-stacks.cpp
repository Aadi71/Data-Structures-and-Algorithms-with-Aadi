// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s.size() == 0){
            s.push(x);
            return;
        } 
        int t = s.top();
        s.pop();
        push(x);
        s.push(t);
    }
    
    int pop() {
        int t = s.top();
        s.pop();
        return t;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return (s.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
