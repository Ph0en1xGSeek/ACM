class Solution {
private:
    int dp[11] = {0};
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n >= 10) {
            n = 10;
        }
        return dp[n];
    }
    
    Solution() {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 10;
        for(int i = 2; i <= 10; ++i) {
            int tmp = 9;
            for(int j = 0; j < i-1; ++j) {
                tmp *= 9 - j;
            }
            dp[i] = dp[i-1] + tmp;
        }
    }
};


class Solution {
private:
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n >= 10) {
            n = 10;
        }
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return 10;
        }
        int tmp = 10;
        for(int i = 2; i <= n; ++i) {
            int mu = 9;
            for(int j = 0; j < i-1; ++j) {
                mu *= 9 - j;
            }
            tmp += mu;
        }
        return tmp;
    }
};