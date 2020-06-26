class Solution {
public:
    int strToInt(string str) {
        int size = str.size();
        int pos = 0;
        while(pos < size && str[pos] == ' ')
            ++pos;
        int sign = 1;
        if(pos < size) {
            if(str[pos] == '+') {
                sign = 1;
                ++pos;
            }else if(str[pos] == '-') {
                sign = -1;
                ++pos;
            }else if(str[pos] >= '0' && str[pos] <= '9'){
                
            }else {
                return 0;
            }
        }
        long long num = 0;
        if(pos < size && str[pos] >= 0 && str[pos] <= '9') {
            while(num <= INT_MAX && num >= INT_MIN && pos < size && str[pos] >= '0' && str[pos] <= '9') {
                num *= 10;
                num += sign * (str[pos] - '0');
                ++pos;
            }
            if(num > INT_MAX) {
                return INT_MAX;
            }else if(num < INT_MIN) {
                return INT_MIN;
            }else {
                return num; 
            }
        }else {
            return 0;
        }
    }
};