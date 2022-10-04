class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> arr;
    vector<int> minArr;
    MinStack() {
    }
    
    void push(int x) {
        arr.push_back(x);
        if (minArr.size() == 0 || x < minArr.back()) {
            minArr.push_back(x);
        } else {
            minArr.push_back(minArr.back());
        }
    }
    
    void pop() {
        if (arr.size() > 0) {
            arr.pop_back();
            minArr.pop_back();
        }
    }
    
    int top() {
        if (arr.size() > 0) {
            return arr.back();
        }
        return 0;
    }
    
    int min() {
        if (minArr.size() > 0) {
            return minArr.back();
        }
        return INT_MAX;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */