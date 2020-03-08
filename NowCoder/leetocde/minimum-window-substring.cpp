class Solution {
public:
	string minWindow(string S, string T) {
		int len_s = S.size();
		int len_t = T.size();
		if(len_t == 0 || len_s == 0) {
			return "";
		}
		vector<int> cnt(128, 0);
		int num_char = 0;
		for(int i = 0; i < len_t; ++i) {
			if(cnt[T[i]] == 0) {
				++num_char;
			}
			++cnt[T[i]];
		}
		int ans = INT_MAX;
		int ans_pos = 0;
		int left = 0, right = 0;
		while(right < len_s) {
			--cnt[S[right]];
			if(cnt[S[right]] == 0) {
				--num_char;
			}
			++right;
			if(num_char == 0) {
				while(left < right && cnt[S[left]] < 0) {
					++cnt[S[left]];
					++left;
				}
                if(right - left < ans) {
                    ans = right - left;
                    ans_pos = left;
                }
                ++cnt[S[left]];
                ++num_char;
                ++left;
			}
		}
		if(ans == INT_MAX) {
			return "";
		}else {
			return S.substr(ans_pos, ans);
		}
	}
};