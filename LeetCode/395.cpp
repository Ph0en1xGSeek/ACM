class Solution {
public:
    int longestSubstring(string s, int k) {
        int sz = s.size();
        int sum[26] = {0};
        for(int i = 0; i < sz; ++i) {
            ++sum[s[i] - 'a'];
        }
        int flag = true;
        int cur_pos = 0, ans = 0;
        for(int i = 0; i < sz; ++i) {
            if(sum[s[i] - 'a'] < k) {
                ans = max(ans, longestSubstring(s.substr(cur_pos, i - cur_pos), k));
                cur_pos = i + 1;
                flag = false;
            }
        }
        return flag ? sz: max(ans, longestSubstring(s.substr(cur_pos, sz - cur_pos), k));
    }
};