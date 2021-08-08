class CQueue {
public:
    stack<int> arr1;
    stack<int> arr2;

    CQueue() {
    }
    
    void appendTail(int value) {
        arr1.push(value);
    }
    
    int deleteHead() {
        if (arr2.empty()) {
            while (!arr1.empty()) {
                int tmp = arr1.top();
                arr1.pop();
                arr2.push(tmp);
            }
        }
        if (arr2.empty()) {
            return -1;
        }
        int tmp = arr2.top();
        arr2.pop();
        return tmp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */