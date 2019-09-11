class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> mi;
    priority_queue<int, vector<int>, greater<int> > mx;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.size() == 0 && mi.size() == 0) {
            mi.push(num);
            return;
        }
        if(num <= mi.top()) {
            mi.push(num);
        } else {
            mx.push(num);
        }
        
        if(mi.size() + 1 < mx.size()) {
            int tmp = mx.top();
            mx.pop();
            mi.push(tmp);
        } else if(mi.size() > mx.size() + 1) {
            int tmp = mi.top();
            mi.pop();
            mx.push(tmp);
        }
    }
    
    double findMedian() {
        if(mx.size() == 0) {
            return mi.top();
        }else if(mi.size() == 0) {
            return mx.top();
        }else if(mi.size() > mx.size()){
            return mi.top();
        }else if(mx.size() > mi.size()) {
            return mx.top();
        }else {
            return (mi.top() + mx.top()) / 2.0;
        }
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */