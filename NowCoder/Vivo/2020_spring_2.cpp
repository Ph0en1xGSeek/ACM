class Solution {
public:
    /**
     * 输入一个整形数值，返回一个整形值
     * @param n int整型 n>9
     * @return int整型
     */
    int solution(int n) {
        // write code here
        int arr[8] = {0};
        while(n % 2 == 0) {
            ++arr[2];
            n /= 2;
        }
        while(n % 3 == 0) {
            ++arr[3];
            n /= 3;
        }
        while(n % 5 == 0) {
            ++arr[5];
            n /= 5;
        }
        while(n % 7 == 0) {
            ++arr[7];
            n /= 7;
        }
        if(n > 1) {
            return -1;
        }
        int base = 1;
        int ans = 0;
        int tmp = arr[3] / 2;
        arr[3] %= 2;
        for(int i = 0; i < tmp; ++i) {
            ans = ans + 9 * base;
            base *= 10;
        }
        tmp = arr[2] / 3;
        arr[2] %= 3;
        for(int i = 0; i < tmp; ++i) {
            ans = ans + 8 * base;
            base *= 10;
        }
        while(arr[7] > 0) {
            ans = ans + 7 * base;
            base *= 10;
            --arr[7];
        }
        while(arr[2] > 0 && arr[3] > 0) {
            ans = ans + 6 * base;
            base *= 10;
            --arr[2];
            --arr[3];
        }
        while(arr[5] > 0) {
            --arr[5];
            ans = ans + 5 * base;
            base *= 10;
        }
        tmp = arr[2] / 2;
        arr[2] %= 2;
        for(int i = 0; i < tmp; ++i) {
            ans = ans + 4 * base;
            base *= 10;
        }
        while(arr[3] > 0) {
            --arr[3];
            ans = ans + 3 * base;
            base *= 10;
        }
        while(arr[2] > 0) {
            --arr[2];
            ans = ans + 2 * base;
            base *= 10;
        }
        return ans;
    }
};