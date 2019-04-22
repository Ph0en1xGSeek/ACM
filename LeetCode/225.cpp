class MyStack {
public:
    vector<int> v;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        v.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = *(v.end()-1);
        v.pop_back();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        int ret = *(v.end() - 1);
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return v.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */