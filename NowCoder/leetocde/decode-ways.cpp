class Solution {
public:
	int numDecodings(string s) {
		int sz = s.size();
        if(sz > 0 && s[0] == '0'){
            return 0;
        }
		if(sz <= 1) {
			return sz;
		}
		int pre_pre = 0, pre = 1, cur = 1;
		for(int i = 1; i < sz; ++i) {
			pre_pre = pre;
			pre = cur;
            cur = 0;
            if(s[i] != '0') {
                cur += pre;
            }
			if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
				cur += pre_pre;
			}
		}
		return cur;
	}
};