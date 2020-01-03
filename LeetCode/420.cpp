class Solution {
public:
    int strongPasswordChecker(string s) {
        int sz = s.size();
        int lower = 1, upper = 1, digit = 1;
        vector<int> v;
        for(int i = 0; i < sz;) {
            if(s[i] >= '0' && s[i] <= '9') digit = 0;
            if(s[i] >= 'a' && s[i] <= 'z') lower = 0;
            if(s[i] >= 'A' && s[i] <= 'Z') upper = 0;
            int j = i;
            while(i < sz && s[i] == s[j]) ++i;
            if(i - j >= 3)
                v.push_back(i - j);
        }
        int sz_v = v.size();
        int missing = digit + upper + lower;
        if(missing + sz_v == 0 && sz >= 6 && sz <= 20)
            return 0;
        int ret = 0;
        if(sz < 6) {
            int diff = 6 - sz;
            ret += max(diff, missing);
        }else {
            int over = max(sz - 20, 0);
            int left = 0;
            for(int k = 1; k <= 3; ++k) {
                for(int i = 0; i < sz_v && over > 0; ++i) {
                    if(v[i] >= 3 && v[i] % 3 == (k-1)) {
                        int tmp = min(k, over);
                        over -= tmp;
                        v[i] -= tmp;
                        ret += tmp;
                    }
                }
            }
            
            ret += over;
            for(int i = 0; i < sz_v; ++i) {
                
                if(v[i] >= 3) {
                    left += v[i] / 3;
                }
            }
            
            ret += max(missing, left);
        }
        return ret;
    }
};