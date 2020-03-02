class Solution {
public:
	bool isScramble(string s1, string s2) {
		if(s1 == s2) {
			return true;
		}
		int sz1 = s1 .size();
		int sz2 = s2.size();
		if(sz1 != sz2) {
			return false;
		}
		vector<int> cnt(26, 0);
		for(int i = 0; i < sz1; ++i) {
			++cnt[s1[i] - 'a'];
			--cnt[s2[i] - 'a'];
		}
		for(int i = 0; i < 26; ++i) {
			if(cnt[i]) return false;
		}
		for(int i = 1; i < sz1; ++i) {
			if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, sz1 - i), s2.substr(i, sz1- i))) ||
               (isScramble(s1.substr(0, i), s2.substr(sz1-i, i)) && isScramble(s1.substr(i, sz1 - i), s2.substr(0, sz1-i)))) {
				return true;
			}
		}
		return false;
 	}
};
