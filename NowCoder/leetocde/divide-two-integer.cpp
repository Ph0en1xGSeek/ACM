class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool sign = (dividend < 0) ^ (divisor < 0);
        long long long_dividend = labs(dividend);
        long long long_divisor = labs(divisor);
        if(long_dividend < long_divisor) {
            return 0;
        }
        long long ans = 0; 
        long long tmp = 1;
        while((long_divisor << 1) <= long_dividend) {
            long_divisor <<= 1;
            tmp <<= 1;
        }
        while(tmp > 0) {
            if(long_divisor <= long_dividend) {
                ans += tmp;
                long_dividend -= long_divisor;
            }
            tmp >>= 1;
            long_divisor >>= 1;
        }
        return sign? (int)(-ans): (int)(ans);
    }
};