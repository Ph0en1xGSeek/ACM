class Solution {
public:
    int calculate(string s) {
        int sign = 0;
        int res = 0;
        int num;
        int pre = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num *= 10;
                    num += (s[i] - '0');
                    i++;
                }
                i--;
                if(sign == 0) {
                    res += num;
                    pre = num;
                }else if(sign == 1) {
                    res -= num;
                    pre = -num;
                }else if(sign == 2) {
                    res -= pre;
                    res += (pre * num);
                    pre *= num;
                }else if(sign == 3) {
                    res -= pre;
                    res += (pre / num);
                    pre /= num;
                }
            }else if(s[i] == '+') {
                sign = 0;
            }else if(s[i] == '-') {
                sign = 1;
            }else if(s[i] == '*') {
                sign = 2;
            }else if(s[i] == '/') {
                sign = 3;
            }
        }
        return res;
    }
};