class Solution {
public:
    string num2str(int num) {
        string ans;
        while(num > 0) {
            ans += num % 10 + '0';
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    long long str2num(string &str) {
        long long ans = 0;
        int size = str.size();
        for(int i = 0; i < size; ++i) {
            ans *= 10;
            ans += str[i] - '0';
        }
        return ans;
    }

    int nextGreaterElement(int n) {
        string str = num2str(n);
        int size = str.size();
        if(size <= 1) {
            return -1;
        }
        int pos = size - 2;
        while(pos >= 0 && str[pos] >= str[pos + 1]) {
            --pos;
        }
        if(pos == -1) {
            return -1;
        }
        int tmp = pos;
        while(tmp + 1 < size && str[tmp + 1] > str[pos]) {
            ++tmp;
        }
        swap(str[pos], str[tmp]);
        reverse(str.begin() + pos + 1, str.end());
        long long ans = str2num(str);
        if(ans > INT_MAX) {
            return -1;
        }
        return ans;
    }
};