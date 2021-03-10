class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int cnt[256] = {0};
        int sz = str.size();
        for(int i = 0; i < sz; ++i) {
            ++cnt[str[i]];
        }
        for(int i = 0; i < sz; ++i) {
            if(cnt[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};