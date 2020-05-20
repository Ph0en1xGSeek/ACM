class Solution {
public:
    int countDigitOne(int n) {
        string num;
        if(n == 0) {
            return 0;
        }
        while(n > 0) {
            num += n % 10 + '0';
            n /= 10;
        }
        reverse(num.begin(), num.end());
        return cnt(num);
    }

    int cnt(string num) {
        int size = num.size();
        if(size == 1) {
            if(num[0] == '0') {
                return 0;
            }else {
                return 1;
            }
        }
        int ret = 0;
        if(num[0] == '1') {
            ret += str2num(num.substr(1, size-1)) + 1;
        }else if(num[0] > '1') {
            ret += powBase10(size-1);
        }
        ret += (num[0] - '0') * (size - 1) * powBase10(size - 2);
        ret += cnt(num.substr(1, size-1));
        return ret;
    }

    int str2num(string str) {
        int size = str.size();
        int ans = 0;
        for(int i = 0; i < size; ++i) {
            ans *= 10;
            ans += str[i] - '0';
        }
        return ans;
    }

    int powBase10(int n) {
        int ans = 1;
        while(n--) {
            ans *= 10;
        }
        return ans;
    }
};