class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        import re
        minus = 1
        if len(str) == 0:
            return 0
        str = str.strip()
        i = 0
        while i < len(str):
            if i == 0 and (str[i] == '-' or str[i] == '+') and minus == 1:
                minus = -1
            elif str[i] not in ['0','1','2','3','4','5','6','7','8','9']:
                break
            i += 1
        if i == 0 or (i == 1 and minus == -1):
            return 0
        res = int(str[0:i])
        res = min(res, 2147483647)
        res = max(res, -2147483648)
        return res


class Solution {
public:

    inline bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    inline bool isSign(char ch) {
        return ch == '+' || ch == '-';
    }

    int myAtoi(string s) {
        int size = s.size();
        int ans = 0;
        int sign = 1;
        int i;
        for (i = 0; i < size && s[i] == ' '; ++i);
        if (i == size) {
            return ans;
        }
        if (isSign(s[i])) {
            if (s[i] == '-') {
                sign = -1;
            }
            ++i;
        }
        for (; i < size && isDigit(s[i]); ++i) {
            int num = s[i] - '0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && num >= 7)) {
                return INT_MAX;
            } else if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && num >= 8)) {
                return INT_MIN;
            }
            ans = ans * 10 + num * sign;
        }
        return ans;
    }
};