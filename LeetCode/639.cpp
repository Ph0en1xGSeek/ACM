class Solution {
public:
	int numDecodings(string s) {
		int sz = s.size();
		if(sz == 0) {
			return 0;
		}
		if(sz == 1) {
			if(s[0] == '0') return 0;
			else if(s[0] >= '1' && s[0] <= '9') return 1;
			else return 9;
		}
		long long pre_pre = 0, pre = 1, cur = 1;
        if(s[0] == '*') {
            cur = 9;
        }else if(s[0] == '0') {
            return 0;
        }
		for(int i = 1; i < sz; ++i) {
			pre_pre = pre;
			pre = cur;
			cur = 0;
			if(s[i] == '*') cur = (cur + (9 * pre) % mod) % mod;
			else if(s[i] != '0') cur =  (cur + pre) % mod;
			
			if(s[i-1] == '1' && s[i] == '*') {
				cur = (cur + (9 * pre_pre) % mod) % mod;
			}else if(s[i-1] == '1') {
				cur = (cur + pre_pre) % mod;
			}else if(s[i-1] == '2' && s[i] == '*') {
				cur = (cur + (6 * pre_pre) % mod) % mod;
			}else if(s[i-1] == '2' && (s[i] >= '0' && s[i] <= '6')) {
				cur = (cur + pre_pre) % mod;
			}else if(s[i-1] == '*' && (s[i] >= '0' && s[i] <= '6')) {
				cur = (cur + (2 * pre_pre) % mod) % mod;
			}else if(s[i-1] == '*' && s[i] != '*') {
				cur = (cur + pre_pre) % mod;
			}else if(s[i-1] == '*' && s[i] == '*') {
                cur = (cur + (15 * pre_pre) % mod) % mod;
            }
		}
		return cur;
	}
private:
	const int mod = 1000000007;
};
