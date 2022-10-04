class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[52] = {0};
        int sz = s.size();
        for(int i = 0; i < sz; ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                ++cnt[s[i] - 'A'];
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                ++cnt[s[i] - 'a' + 26];
            }
        }
        bool hasOdd = false;
        int ans = 0;
        for(int i = 0; i < 52; ++i) {
            ans += (cnt[i] / 2) * 2;
            if(cnt[i] & 1) {
                hasOdd = true;
            }
        }
        if(hasOdd) {
            ++ans;
        }
        return ans;
    }
};