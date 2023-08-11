//155. Min Stack
class MinStack {
public:
    stack<vector<int>> dummy;

    void push(int val) {
        if (dummy.empty()) {
            dummy.push({ val, val });
            return;
        }
        int cur = dummy.top()[1];
        dummy.push({ val, min(cur, val) });
    }

    void pop() {
        dummy.pop();
    }

    int top() {
        return dummy.top()[0];
    }

    int getMin() {
        return dummy.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */