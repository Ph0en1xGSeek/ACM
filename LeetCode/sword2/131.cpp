class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len < 2) {
            return 0;
        } else if (bamboo_len == 2) {
            return 1;
        } else if (bamboo_len == 3) {
            return 2;
        }
        int three = bamboo_len / 3;
        int remain = bamboo_len % 3;
        if (remain == 1) {
            return pow(3, three - 1) * 4;
        } else if (remain == 0) {
            return pow(3, three);
        } else {
            return pow(3, three) * 2;
        }
    }
};