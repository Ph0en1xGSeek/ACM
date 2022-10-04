class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int sz = p.size();
        if(sz == 0) {
            return 0;
        }
        vector<int> cnt(26, 0);
        int len = 1;
        cnt[p[0] - 'a'] = 1;
        for(int i = 1; i < sz; ++i) {
            if(p[i] - 'a' == (p[i-1] - 'a' + 1) % 26) {
                ++len;
            }else {
                len = 1;
            }
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], len);
        }
        int ans = 0;
        for(int i = 0; i < 26; ++i) {
            ans += cnt[i];
        }
        return ans;
    }
};