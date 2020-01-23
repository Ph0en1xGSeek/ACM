class Solution {
public:
    int StrToInt(string str) {
        size_t sz = str.size();
        if(sz == 0) {
            return 0;
        }
        long long num = 0;
        int sign = 1;
        size_t pos = 0;
        if(str[pos] == '+') {
            sign = 1;
            ++pos;
        }else if(str[pos] == '-') {
            sign = -1;
            ++pos;
        }
        while(pos < sz) {
            if(str[pos] < '0' || str[pos] > '9') {
                return 0;
            }
            num = num * 10 + sign * (str[pos] - '0');
            if((sign == 1 && num > INT_MAX) || (sign == -1 && num < INT_MIN)) {
                return 0;
            }
            ++pos;
        }
        return (int)(num);
    }
};