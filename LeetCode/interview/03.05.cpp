class SortedStack {
private:
    stack<int> mi_st;
    stack<int> mx_st;
public:
    SortedStack() {

    }
    
    void push(int val) {
        while(!mi_st.empty() && val < mi_st.top()) {
            mx_st.push(mi_st.top());
            mi_st.pop();
        }
        while(!mx_st.empty() && val > mx_st.top()) {
            mi_st.push(mx_st.top());
            mx_st.pop();
        }
        mi_st.push(val);
    }
    
    void pop() {
        if(isEmpty()) {
            return;
        }
        while(!mi_st.empty()) {
            mx_st.push(mi_st.top());
            mi_st.pop();
        }
        mx_st.pop();
    }
    
    int peek() {
        if(isEmpty()) {
            return -1;
        }
        while(!mi_st.empty()) {
            mx_st.push(mi_st.top());
            mi_st.pop();
        }
        return mx_st.top();
    }
    
    bool isEmpty() {
        return (mi_st.empty() && mx_st.empty());
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */