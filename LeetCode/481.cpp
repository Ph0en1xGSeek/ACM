class Solution {
public:
    int magicalString(int n) {
        if(n == 0) {
            return 0;
        }
        if(n < 3) {
            return 1;
        }
        string str = "122";
        str.reserve(n + 1);
        int pos = 2;
        int len = 3;
        int ans = 1;
        while(len < n) {
            int num = str[pos] - '0';
            len += num;
            if(str.back() == '2') {
                ans += num;
            }
            str += string(num, str.back() ^ 3);
            ++pos;
        }
        if(len == n + 1 && str.back() == '1') {
            --ans;
        }
        return ans;
    }
};