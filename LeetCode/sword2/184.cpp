class Checkout {
    int left;
    int right;
    deque<pair<int, int>> q;
    list<int> arr;
public:
    Checkout() : left(0), right(0) {

    }
    
    int get_max() {
        if(q.empty()) {
            return -1;
        }
        return q.front().second;
    }
    
    void add(int value) {
        while(!q.empty() && q.back().second <= value) {
            q.pop_back();
        }
        q.push_back({right++, value});
        arr.push_back(value);
    }
    
    int remove() {
        if(arr.empty()) {
            return -1;
        }
        if (q.front().first <= left) {
            q.pop_front();
        }
        ++left;
        int ret = arr.front();
        arr.pop_front();
        return ret;
    }

};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */