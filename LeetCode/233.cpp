class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;
        for(long long m = 1; m <= n; m *= 10) {
            int tmp1 = n / m, tmp2 = n % m;
            ans += (tmp1 + 8) / 10 * m;
            ans += ((tmp1 % 10) == 1) ? (tmp2 + 1): 0;
        }
        return ans;
    }
};