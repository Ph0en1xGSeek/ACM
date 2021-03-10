class Solution {
public:
    void push(int value) {
        st.push(value);
        if(mi.empty()) {
            mi.push(value);
        }else {
            int cur_mi = std::min(mi.top(), value);
            mi.push(cur_mi);
        }
    }
    void pop() {
        st.pop();
        mi.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return mi.top();
    }
private:
    stack<int> st;
    stack<int> mi;
};