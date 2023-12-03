class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int left = 0, right = x;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (((long long) mid * mid) <= x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};