class Solution {
public:
    int digitOneInNumber(int num) {
        int high = num / 10;
        int low = 0;
        long long digit = 1;
        int cur = num % 10;
        int res = 0;
        while (high != 0 || cur != 0) {
            if (cur == 0) {
                res += high * digit;
            } else if (cur == 1) {
                res += high * digit + low + 1;
            } else {
                res += (high + 1) * digit;
            }
            low += digit * cur;
            digit *= 10;
            cur = high % 10;
            high /= 10;
        }
        return res;
    }
};