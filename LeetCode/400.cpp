class Solution {
public:
    int findNthDigit(int n) {
        long long arr[10] = {0};
        long long tmp = 9;
        for(int i = 1; i <= 9; ++i) {
            arr[i] = (long long)tmp * i;
            tmp *= 10;
        }
        int pos = 1;
        while(n > arr[pos]) {
            n -= arr[pos];
            ++pos;
        }
        if(pos > 1) {
            int nth = (n - 1) / pos;
            int remain = (n - 1) % pos;
            int base = 10;
            for(int i = 0; i < pos - 2; ++i) {
                base *= 10;
            }
            base += nth;
            for(int i = 0; i < (pos - remain - 1); ++i) {
                base /= 10;
            }
            return base % 10;
        }else {
            return n;
        }
    }
};