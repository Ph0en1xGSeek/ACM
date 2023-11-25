class Solution {
private:
    const int MOD = 1e9+7;
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len < 2) {
            return 0;
        } else if (bamboo_len == 2) {
            return 1;
        } else if (bamboo_len == 3) {
            return 2;
        }
        int three = bamboo_len / 3 - 1;
        int remain = bamboo_len % 3;
        long long ans = 1;
        long long tmp = 3;
        while (three) {
            if (three & 1) {
                ans = (ans * tmp) % MOD;
            }
            tmp = (tmp * tmp) % MOD;
            three >>= 1;
        }


        if (remain == 1) {
            return (int) (ans * 4 % MOD);
        } else if (remain == 0) {
            return (int) (ans * 3 % MOD);
        } else {
            return (int) (ans * 6 % MOD);
        }
    }
};