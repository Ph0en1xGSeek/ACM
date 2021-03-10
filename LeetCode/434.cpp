class Solution {
public:
    int countSegments(string s) {
        int sz = s.size();
        if(sz == 0) {
            return 0;
        }
        int pos = 0;
        int cnt = 0;
        while(pos < sz) {
            if(s[pos] != ' ') {
                ++cnt;
                while(pos < sz && s[pos] != ' ') {
                    ++pos;
                }
            }else {
                ++pos;
            }
        }
        return cnt;
    }
};