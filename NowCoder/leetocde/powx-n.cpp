class Solution {
public:
	double myPow(double x, int n) {
        if(x < 0.00001 && x > -0.00001) {
            return 0;
        }
		if(n == 0) {
			return 1.0;
		}
        bool flag = false;
        if(n < 0) {
            if(n == INT_MIN) {
                n /= 2;
                x *= x;
            }
            n = -n;
            flag = true;
        }
		double ans = 1.0;
		while(n > 0) {
			if(n & 1) {
				ans *= x;
			}
			x *= x;
			n >>= 1;
		}
        if(flag) {
            return 1.0 / ans;
        }else {
            return ans;
        }
	}
};