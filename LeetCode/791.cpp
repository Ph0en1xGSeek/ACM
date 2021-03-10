class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> cnt(26, 0);
        int size = T.size();
        for(int i = 0; i < size; ++i) {
            ++cnt[T[i] - 'a'];
        }
        string ans;
        int size_S = S.size();
        for(int i = 0; i < size_S; ++i) {
            for(int j = 0; j < cnt[S[i] - 'a']; ++j) {
                ans += S[i];
            }
            cnt[S[i] - 'a'] = 0;
        }
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] != 0) {
                for(int j = 0; j < cnt[i]; ++j) {
                    ans += (i + 'a');
                }
            }
        }
        return ans;
    }
};
