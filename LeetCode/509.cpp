class Solution {
public:
    int fib(int N) {
        if(N == 0) {
            return 0;
        }
        if(N == 1) {
            return 1;
        }
        int cur = 1;
        int pre = 0;
        for(int i = 2; i <= N; ++i) {
            int tmp = pre + cur;
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};