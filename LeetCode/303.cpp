class NumArray {
public:
    NumArray(vector<int>& nums) {
        sz = nums.size();
        arr.resize(sz+1);
        for(int i = 0; i < sz; ++i) {
            update(i+1, nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        long long sumj = cnt(j+1);
        long long sumi = cnt(i);
        return sumj - sumi;
    }

private:
    int sz;
    vector<long long> arr;
    
    int lowbit(int x) {
        return x & (-x);
    }
    
    void update(int pos, int num) {
        while(pos <= sz) {
            arr[pos] += num;
            pos += lowbit(pos);
        }
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
 * int param_1 = obj->sumRange(i,j);
 */