class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }

    int readNum(string &str, int &pos) {
        int ret = 0;
        int size = str.size();
        while(pos < size && str[pos] >= '0' && str[pos] <= '9') {
            ret *= 10;
            ret += str[pos++] - '0';
        }
        return ret;
    }

    string num2str(int num) {
        string ret;
        if(num == 0) {
            return "0";
        }
        while(num > 0) {
            ret += num % 10 + '0';
            num /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string fractionAddition(string expression) {
        int size = expression.size();
        vector<int> numerators;
        vector<int> denominators;
        vector<int> sign;
        int pos = 0;
        while(pos < size) {
            if(pos == 0) {
                if(expression[pos] == '+' || expression[pos] == '-') {
                    if(expression[pos++] == '+') {
                        sign.push_back(1);
                    }else {
                        sign.push_back(-1);
                    }
                }else {
                    sign.push_back(1);
                }
            }else {
                if(expression[pos++] == '+') {
                    sign.push_back(1);
                }else {
                    sign.push_back(-1);
                }
            }

            numerators.push_back(readNum(expression, pos));
            ++pos;
            denominators.push_back(readNum(expression, pos));
        }
        int cur_num = 0;
        int cur_den = 1;
        int cur_sign = 1;
        size = sign.size();
        for(int i = 0; i < size; ++i) {
            int nex_num = cur_sign * cur_num * denominators[i] + sign[i] * cur_den * numerators[i];
            int nex_den = cur_den * denominators[i];
            if(nex_num < 0) {
                nex_num = -nex_num;
                cur_sign = -1;
            }else {
                cur_sign = 1;
            }
            int g = gcd(nex_num, nex_den);
            cur_num = nex_num / g;
            cur_den = nex_den / g;
        }
        string ans;
        if(cur_sign == -1) {
            ans += '-';
        }
        ans += num2str(cur_num) + "/" + num2str(cur_den);
        return ans;
    }
};