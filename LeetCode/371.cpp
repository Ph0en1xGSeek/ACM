class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int c = a ^ b;
            b = (unsigned)(a & b) << 1;
            a = c;
        }
        return a;
    }
};