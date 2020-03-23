class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();
        int s_sz = sz;
        sz = sz * 2 + 2;
        int ans = 0;
        string str(sz, '#');
        vector<int> dp(sz, 1);
        str[0] = '$';
        for(int i = 0; i < s_sz; ++i) {
            str[(i << 1) + 2] = s[i];
        }
        int border = 0, id = 0;
        for(int i = 1; i < sz; ++i) {
            if(i < border) {
                dp[i] = min(dp[id - (i - id)], border - i);
            }
            
            while(str[i + dp[i]] == str[i - dp[i]]) {
                ++dp[i];
            }
            if(i + dp[i] > border) {
                border = i + dp[i];
                id = i;
            }
            ans += (dp[i] >> 1);
        }
        return ans;
    }
};