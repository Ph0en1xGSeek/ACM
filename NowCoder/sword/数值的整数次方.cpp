class Solution {
public:
    double Power(double base, int exponent) {
        Invalid = false;
        if(equal(base, 0.0)) {
            if(exponent < 0) {
                Invalid = true;
            }
            return 0.0;
        }
        unsigned int absexp = exponent < 0? -exponent: exponent;
        double ret = PowerWithUnsignedInt(base, absexp);
        if(exponent < 0) {
            return 1.0 / ret;
        }else {
            return ret;
        }
    }
    
    double PowerWithUnsignedInt(double base, unsigned int exponent) {
        double ans = 1.0;
        while(exponent) {
            if(exponent & 1) {
                ans *= base;
            }
            base *= base;
            exponent >>= 1;
        }
        return ans;
    }
    
    bool equal(bool a, bool b) {
        if(a - b > -0.0001 && a - b < 0.0001) {
            return true;
        }
        return false;
    }
    bool Invalid = false;
};