struct TreeArray {
    vector<int> arr;
    int n;

    TreeArray(int _n) : n(_n), arr(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) {
        x = min(x, n);
        int ans = 0;
        while (x > 0) {
            ans += arr[x];
            x -= lowbit(x);
        }
        return ans;
    }

    void update(int x, int data) {
        x = max(x, 0);
        while(x <= n) {
            arr[x] += data;
            x += lowbit(x);
        }
    }
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        TreeArray treeArray(n + m);
        vector<int> pos(m + 1);
        for (int i = 1; i <= m; ++i) {
            pos[i] = n + i;
            treeArray.update(n + i, 1);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int &cur = pos[queries[i]];
            treeArray.update(cur, -1);
            ans[i] = treeArray.query(cur);
            cur = n - i;
            treeArray.update(cur, 1);
        }
        return ans;
    }
};