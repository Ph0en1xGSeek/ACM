class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0) {
            return 0;
        }
        vector<int> ans(n);
        ans[0] = 1;
        int pos2 = 0, pos3 = 0, pos5 = 0;
        for(int i = 1; i < n; ++i) {
            int mi = ans[pos2] * 2;
            mi = min(mi, ans[pos3] * 3);
            mi = min(mi, ans[pos5] * 5);
            if(mi == ans[pos2] * 2) {
                ++pos2;
            }
            if(mi == ans[pos3] * 3) {
                ++pos3;
            }
            if(mi == ans[pos5] * 5) {
                ++pos5;
            }
            ans[i] = mi;
        }
        return ans[n-1];
    }
};
