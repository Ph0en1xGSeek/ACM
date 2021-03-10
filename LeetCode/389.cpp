class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26] = {0};
        int t_sz = t.size();
        for(int i = 0; i < t_sz; ++i)
            ++cnt[t[i] - 'a'];
        int s_sz = s.size();
        for(int i = 0; i < s_sz; ++i) {
            --cnt[s[i] - 'a'];
        }
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] > 0) {
                return i + 'a';
            }
        }
        return 'a';
    }
};