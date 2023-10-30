class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (auto& num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (miq.size() < k) {
            miq.push(val);
        } else if (val > miq.top()) {
            int tmp = miq.top();
            miq.pop();
            miq.push(val);
        } 
        return miq.top();
    }
private:
    int k;
    // 小顶堆
    priority_queue<int, vector<int>, greater<int> > miq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */