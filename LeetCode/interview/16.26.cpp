class Solution {
public:
    int calculate(string s) {
        int size = s.size();
        int pos = 0;
        int ans = 0;
        int pre_op = 0;
        int pre_oprand = 0;
        int sign = 1;
        int num;
        while(pos < size) {
            if(s[pos] == '+') {
                sign = 1;
                ++pos;
            }else if(s[pos] == '-') {
                sign = 2;
                ++pos;
            }else if(s[pos] == '*') {
                pre_op = sign;
                pre_oprand = num;
                sign = 3;
                ++pos;
            }else if(s[pos] == '/') {
                pre_op = sign;
                pre_oprand = num;
                sign = 4;
                ++pos;
            }else if(s[pos] == ' ') {
                ++pos;
                continue;
            }else {
                num = str2num(s, pos);
                if(sign == 1) {
                    ans += num;
                }else if(sign == 2) {
                    ans -= num;
                }else if(sign == 3) {
                    num *= pre_oprand;
                    if(pre_op == 1) {
                        ans -= pre_oprand;
                        ans += num;
                    }else if(pre_op == 2) {
                        ans += pre_oprand;
                        ans -= num;
                    }
                    sign = pre_op;
                }else {
                    num = pre_oprand / num;
                    if(pre_op == 1) {
                        ans -= pre_oprand;
                        ans += num;
                    }else if(pre_op == 2) {
                        ans += pre_oprand;
                        ans -= num;
                    }
                    sign = pre_op;
                }
            }
        }
        return ans;
    }

    int str2num(string &num, int &from) {
        int ret = 0;
        int size = num.size();
        while(from < size && num[from] >= '0' && num[from] <= '9') {
            ret *= 10;
            ret += num[from] - '0';
            ++from;
        }
        return ret;
    }
};