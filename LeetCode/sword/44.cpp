class Solution {
public:
    long long arr[9];
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        arr[0] = 9;
        for(int i = 1; i <= 8; ++i) {
            arr[i] = arr[i-1] * 10;
        }
        int pos = 0;
        while(n > arr[pos] * (pos + 1)) {
            n -= arr[pos] * (pos + 1);
            ++pos;
        }
        // pos + 1
        --n;
        int num = n / (pos + 1);
        int remain = n % (pos + 1);
        int base = 1;
        for(int i = 0; i < pos; ++i) {
            base *= 10;
        }
        num += base;
        for(int i = 0; i < pos - remain; ++i) {
            num /= 10;
        }
        return num % 10;
    }
};