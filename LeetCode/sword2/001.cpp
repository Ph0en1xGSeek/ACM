class Solution {
public:
    int divide(int a, int b) {
        long long la = a;
        long long lb = b;
        int sign = 1;
        if (la < 0) {
            sign = -sign;
            la = -la;
        }
        if (lb < 0) {
            sign = -sign;
            lb = -lb;
        }
        long long ans = la / lb * sign;
        if (ans > INT_MAX) {
            ans = INT_MAX;
        }
        return ans;
    }
};