class Solution {
public:
    int cutRope(int number) {
        if(number <= 1) {
            return 0;
        }
        if(number == 2) {
            return 1;
        }
        if(number == 3) {
            return 2;
        }
        vector<int> dp(number+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int num = 4; num <= number; ++num) {
            int mx = num;
            for(int i = 1; i <= num / 2; ++i) {
                mx = max(mx, dp[i] * dp[num - i]);
            }
            dp[num] = mx;
        }
        return dp[number];
    }
};


class Solution {
public:
    int cutRope(int number) {
        if(number == 2) {
            return 1;
        }else if(number == 3) {
            return 2;
        }
        int div = number / 3;
        int rem = number % 3;
        if(rem == 0) {
            return pow(3, div);
        }else if(rem == 1) {
            return pow(3, div-1) * 4;
        }else {
            return pow(3, div) * 2;
        }
    }
};