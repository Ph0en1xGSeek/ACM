class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int size = S.size();
        int dash_cnt = 0;
        for(int i = 0; i < size; ++i) {
            if(S[i] == '-') {
                ++dash_cnt;
            }
        }
        int ch_cnt = size - dash_cnt;
        int new_size = ch_cnt + max(0, ((ch_cnt - 1) / K));
        string ans = string(new_size, ' ');
        int pos = new_size - 1;
        int cur = size - 1;
        int cnt = 0;
        while(cur >= 0 && pos >= 0) {
            if(S[cur] == '-') {
                --cur;
                continue;
            }else if(S[cur] >= 'a' && S[cur] <= 'z') {
                ans[pos] = S[cur] - 'a' + 'A';
                --pos;
                --cur;
                ++cnt;
            }else {
                ans[pos--] = S[cur--];
                ++cnt;
            }
            if(pos > 0 && cnt != 0 && cnt % K == 0) {
                ans[pos--] = '-';
            }
        }
        return ans;
    }
};