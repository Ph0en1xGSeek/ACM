class Solution {
public:
    int fib(int n) {
        if(n == 0) {
            return 0;
        }else if(n == 1) {
            return 1;
        }else if(n == 2) {
            return 1;
        }
        int cur = 1, pre_pre = 0, pre = 1;
        for(int i = 3; i <= n; ++i) {
            pre_pre = pre;
            pre = cur;
            cur = (pre_pre + pre) % 1000000007;
        }
        return cur;
    }
};