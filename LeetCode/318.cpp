class Solution {
public:
    int maxProduct(vector<string>& words) {
        int sz = words.size();
        vector<int> mark(sz, 0);
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < words[i].size(); ++j) {
                mark[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        int ans = 0;
        for(int i = 0; i < sz; ++i) {
            for(int j = i+1; j < sz; ++j) {
                if((mark[i] & mark[j]) == 0) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};