class Solution {
public:
    int numWays(int n) {
        if (n == 0) {
            return 1;
        }
        if (n <= 2) {
            return n;
        }
        vector<int> arr(3);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        for (int i = 3; i <= n; ++i) {
            arr[i % 3] = (arr[(i - 1) % 3] + arr[(i - 2) % 3]) % 1000000007;
        }
        return arr[n % 3];
    }
};