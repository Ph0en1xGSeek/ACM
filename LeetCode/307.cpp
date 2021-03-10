class NumArray {
public:
    int sz;
    vector<long long> arr;
    vector<int> source;
    NumArray(vector<int>& nums) {
        sz = nums.size();
        arr.resize(sz+1);
        source.resize(sz+1);
        for(int i = 0; i < sz; ++i) {
            update(i, nums[i]);
            source[i+1] = nums[i];
        }
    }
    
    void update(int i, int val) {
        ++i;
        int dif = val - source[i];
        source[i] = val;
        while(i <= sz) {
            arr[i] += dif;
            i += lowbit(i);
        }
    }
    
    int sumRange(int i, int j) {
        long long sumj = cnt(j+1);
        long long sumi = cnt(i);
        return sumj - sumi;
    }
    
    int lowbit(int x) {
        return x & (-x);
    }
    
    long long cnt(int pos) {
        long long sum = 0;
        while(pos > 0) {
            sum += arr[pos];
            pos -= lowbit(pos);
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */