class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }
        if(n == 4) {
            return 4;
        }
        int div = n / 3;
        int remain = n % 3;
        if(remain == 1) {
            --div;
            remain = 4;
        }
        long long ans = 1;
        while(div--) {
            ans = (ans * 3) % 1000000007;
        }
        if(remain != 0)
            ans = (ans * remain) % 1000000007;
        return ans;
    }
};