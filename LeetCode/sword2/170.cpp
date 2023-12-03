class BIT {
private:
    vector<int> tree;
    int n;
public:

    BIT(int _n) : n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) {
        int ret = 0;
        while (x) {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }

};

class Solution {
public:
    int reversePairs(vector<int>& record) {
        int size = record.size();
        vector<int> tmp = record;
        sort(tmp.begin(), tmp.end());
        for (auto &num : record) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }
        BIT bit(size);
        int ans = 0;
        for (int i = size - 1; i >= 0; --i) {
            ans += bit.query(record[i] - 1);
            bit.update(record[i]);
        }
        return ans;
    }
};