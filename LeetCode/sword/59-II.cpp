class MaxQueue {
private:
    int left;
    int right;
    deque<pair<int, int>> q;
    list<int> arr;
public:
    MaxQueue(): left(0), right(0) {

    }
    
    int max_value() {
        while(!q.empty() && q.front().first < left) {
            q.pop_front();
        }
        if(q.empty()) {
            return -1;
        }
        return q.front().second;
    }
    
    void push_back(int value) {
        while(!q.empty() && q.back().second <= value) {
            q.pop_back();
        }
        q.push_back({right++, value});
        arr.push_back(value);
    }
    
    int pop_front() {
        if(arr.empty()) {
            return -1;
        }
        ++left;
        int ret = arr.front();
        arr.pop_front();
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */