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
        int ans = 1;
        while(div--) {
            ans *= 3;
        }
        if(remain != 0)
            ans *= remain;
        return ans;
    }
};