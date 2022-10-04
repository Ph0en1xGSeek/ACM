class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int sz = s.size();
        if(sz == 0) {
            return 0;
        }
        int cnt[26] = {0};
        int mxCnt = 0;
        int res = 0;
        for(int i = 0; i < sz; ++i) {
            mxCnt = max(mxCnt, ++cnt[s[i] - 'A']);
            while(i - start + 1 - mxCnt > k) {
                --cnt[s[start] - 'A'];
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};