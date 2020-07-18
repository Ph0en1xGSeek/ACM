class Solution {
public:
    int lastRemaining(int n, int m) {
        int num = 0;
        for(int i = 2; i <= n; ++i) {
            num = (num + m) % i;
        }
        return num;
    }
};