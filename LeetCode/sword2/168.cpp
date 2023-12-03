class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_number(n);
        ugly_number[0] = 1;
        int pos2 = 0, pos3 = 0, pos5 = 0;
        for (int i = 1; i < n; ++i) {
            int next2 = ugly_number[pos2] * 2;
            int next3 = ugly_number[pos3] * 3;
            int next5 = ugly_number[pos5] * 5;
            int tmp = min(next2, next3);
            tmp = min(tmp, next5);
            ugly_number[i] = tmp;
            if (next2 == tmp) {
                ++pos2;
            }
            if (next3 == tmp) {
                ++pos3;
            }
            if (next5 == tmp) {
                ++pos5;
            }
        }
        return ugly_number[n - 1];
    }
};