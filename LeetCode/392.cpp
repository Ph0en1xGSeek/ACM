class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_sz = s.size();
        int t_sz = t.size();
        int i = 0, j = 0;
        while(i < s_sz && j < t_sz) {
            if(s[i] != t[j]) {
                ++j;
            }else {
                ++i, ++j;
            }
        }
        if(i == s_sz) {
            return true;
        }else {
            return false;
        }
    }
};