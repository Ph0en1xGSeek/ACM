class MovingAverage {
private:
    int size;
    int total;
    list<int> l;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): size(size), total(0) {
        
    }
    
    double next(int val) {
        if (l.size() == size) {
            total -= l.front();
            l.pop_front();
        }
        total += val;
        l.push_back(val);
        return total * 1.0 / l.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */