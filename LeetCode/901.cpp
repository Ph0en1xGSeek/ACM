class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        arr.push_back(price);
        while(!st.empty() && arr[st.top()] <= price) {
            st.pop();
        }
        int ans;
        if (st.empty()) {
            ans = arr.size();
        } else {
            ans = arr.size() - 1 - st.top();
        }
        st.push(arr.size() - 1);
        return ans;
    }
private:
    stack<int> st;
    vector<int> arr;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */