class Solution {
public:
    int findComplement(int num) {
        int tmp = 0;
        while(tmp <= 31 && (1 << tmp) <= num) {
            ++tmp;
        }
        if(tmp == 32) {
            return (num ^ INT_MAX);
        }else {
            return (num ^ ((1 << tmp) - 1));
        }
    }
};