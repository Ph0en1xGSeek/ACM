class Solution {
public:
    int compress(vector<char>& chars) {
        int pos = 0;
        int cur = 0;
        int sz = chars.size();
        if(sz <= 1) {
            return sz;
        }
        int sum = 0;
        int cnt;
        while(pos < sz) {
            chars[cur++] = chars[pos];
            cnt = 1;
            while(pos+1 < sz && chars[pos+1] == chars[pos]) {
                ++cnt;
                ++pos;
            }
            if(cnt > 1) {
                sum = cur;
                while(cnt > 0) {
                    chars[cur++] = (cnt % 10) + '0';
                    cnt /= 10;
                }
                reverse(chars.begin() + sum, chars.begin() + cur);
            }
            ++pos;
        }
        return cur;
    }
};