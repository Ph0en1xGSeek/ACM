class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0 || m == 0) {
            return -1;
        }
        int ans = 0;
        for(int i = 2; i <= n; ++i) {
            ans = (ans + m) % i;
        }
        return ans;
    }
};