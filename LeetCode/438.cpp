class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_sz = s.size();
        int p_sz = p.size();
        vector<int> res;
        if(p_sz > s_sz) {
            return res;
        }
        vector<int> cntp(26, 0);
        vector<int> cnts(26, 0);
        for(int i = 0; i < p_sz; ++i) {
            ++cntp[p[i] - 'a'];
            ++cnts[s[i] - 'a'];
        }
        for(int i = p_sz; i <= s_sz; ++i) {
            bool flag = true;
            for(int j = 0; j < 26; ++j) {
                if(cnts[j] != cntp[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                res.push_back(i - p_sz);
            }
            if(i < s_sz) {
                ++cnts[s[i] - 'a'];
                --cnts[s[i - p_sz] - 'a'];
            }
        }
        return res;
    }
};