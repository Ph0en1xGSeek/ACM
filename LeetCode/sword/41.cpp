class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(mi.empty() && mx.empty()) {
            mi.push(num);
        }else if(mi.size() < mx.size()) {
            if(num < mx.top()) {
                mi.push(num);
            }else {
                mi.push(mx.top());
                mx.pop();
                mx.push(num);
            }
        }else if(mx.size() < mi.size()) {
            if(num > mi.top()) {
                mx.push(num);
            }else {
                mx.push(mi.top());
                mi.pop();
                mi.push(num);
            }
        }else {
            if(num < mi.top()) {
                mi.push(num);
            }else {
                mx.push(num);
            }
        }
    }
    
    double findMedian() {
        if(mi.empty() && mx.empty()) {
            return 0.0;
        }else if(mi.empty()) {
            return mx.top();
        }else if(mx.empty()) {
            return mi.top();
        }else {
            if(mi.size() > mx.size()) {
                return mi.top();
            }else if(mx.size() > mi.size()) {
                return mx.top();
            }else {
                return (double)(mx.top() + mi.top()) / 2;
            }
        }
    }
private:
    priority_queue<int, vector<int>, less<int>> mi;
    priority_queue<int, vector<int>, greater<int>> mx;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */