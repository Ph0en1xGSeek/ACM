class Solution {
public:
    int minCut(string s) {
        int sz = s.size();
        if(sz == 0) {
            return 0;
        }
        vector<vector<bool> > isPalindrome(sz, vector<bool>(sz, false));
        vector<int> cut(sz, 0);
        for(int i = 0; i < sz; ++i) {
            cut[i] = i;
            for(int j = 0; j <= i; ++j) {
                if(s[i] == s[j] && (i - j <= 1 || isPalindrome[j+1][i-1])) {
                    isPalindrome[j][i] = true;
                    if(j == 0) {
                        cut[i] = 0;
                    }else {
                        cut[i] = min(cut[i], cut[j-1] + 1);
                    }
                }
            }
        }
        return cut[sz-1];
    }
};