class Solution {
public:
    void fastPow(int (&arr)[2][2], int (&ans)[2][2], int n) {
        int tmp[2][2];
        while(n) {
            if(n & 1) {
                tmp[0][0] = ans[0][0];
                tmp[0][1] = ans[0][1];
                tmp[1][0] = ans[1][0];
                tmp[1][1] = ans[1][1];
                ans[0][0] = tmp[0][0] * arr[0][0] + tmp[0][1] * arr[1][0];
                ans[0][1] = tmp[0][0] * arr[0][1] + tmp[0][1] * arr[1][1];
                ans[1][0] = tmp[1][0] * arr[0][0] + tmp[1][1] * arr[1][0];
                ans[1][1] = tmp[1][0] * arr[0][1] + tmp[1][1] * arr[1][1];
            }
            tmp[0][0] = arr[0][0];
            tmp[0][1] = arr[0][1];
            tmp[1][0] = arr[1][0];
            tmp[1][1] = arr[1][1];
            arr[0][0] = tmp[0][0] * tmp[0][0] + tmp[0][1] * tmp[1][0];
            arr[0][1] = tmp[0][0] * tmp[0][1] + tmp[0][1] * tmp[1][1];
            arr[1][0] = tmp[1][0] * tmp[0][0] + tmp[1][1] * tmp[1][0];
            arr[1][1] = tmp[1][0] * tmp[0][1] + tmp[1][1] * tmp[1][1];
            n >>= 1;
        }
    }
    
    int Fibonacci(int n) {
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        int arr[2][2] = {{1, 1}, {1, 0}};
        int ans[2][2] = {{1, 0}, {0, 1}};
        fastPow(arr, ans, n-1);
        return ans[0][0];
    }
};



class Solution {
public:
    int Fibonacci(int n) {
        int ans = 1;
        if(n == 0) {
            return 0;
        }
        if(n <= 2) {
            return ans;
        }
        int a = 1, b = 1, tmp;
        for(int i = 3; i <= n; ++i) {
            tmp = a;
            a += b;
            b = tmp;
        }
        return a;
    }
};