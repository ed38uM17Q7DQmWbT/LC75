//232. Implement Queue using Stacks
class MyQueue {
public:
    int front;
    stack<int> a;
    stack<int> b;

    void push(int x) {
        if (a.empty())
            front = x;
        a.push(x);
    }

    int pop() {
        if (b.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        int temp = b.top();
        b.pop();
        return temp;
    }

    int peek() {
        if (!b.empty())
            return b.top();
        return front;
    }

    bool empty() {
        return a.empty() && b.empty();
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