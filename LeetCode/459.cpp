class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int sz = s.size();
        if(sz <= 1) {
            return false;
        }
        vector<int> nex(sz+1);
        nex[0] = -1;
        int i = 0, j = -1;
        while(i < sz) {
            while(j != -1 && s[j] != s[i]) {
                j = nex[j];
            }
            ++j;
            ++i;
            nex[i] = j;
        }
        if(sz % (sz - nex[sz]) == 0 && nex[sz] != 0) {
            return true;
        }else {
            return false;
        }
    }
};