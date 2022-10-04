class Solution {
public:
    double myPow(double x, int n) {
        bool flag = false;
        if (abs(x - 1.0) <= 1e-6) {
            return 1.0;
        }
        if (n == 0) {
            return 1.0;
        } else if (n < 0) {
            if (n == INT_MIN) {
                if (abs(x + 1.0) <= 1e-6) {
                    return 1.0;
                }
                return 0;
            }
            n = -n;
            flag = true;
        }
        double result = 1.0;
        while(n > 0) {
            if (n & 1) {
                result *= x;
            }
            x *= x;
            n >>= 1;
        }
        if (flag) {
            result = 1 / result;
        }
        return result;
    }
};