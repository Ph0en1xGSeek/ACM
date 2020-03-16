class Solution {
public:
	int minStickers(vector<string> &stickers, string target) {
		int size = target.size();
		int n = 1 << size;
		if(size == 0) {
			return 0;
		}
		vector<int> dp(n, INT_MAX);
		dp[0] = 0;
		for(int i = 0; i < n; ++i) {
			if(dp[i] == INT_MAX) {
				continue;
			}
			for(string &sticker: stickers) {
				int cur = i;
				for(char c: sticker) {
					for(int j = 0; j < size; ++j) {
						if(((1 << j) & cur) == 0 && c == target[j]) {
							cur |= (1 << j);
							break;
						}
					}
				}
				dp[cur] = min(dp[cur], dp[i] + 1);
			}
		}
		if(dp[n - 1] == INT_MAX) {
			return -1;
		}else {
			return dp[n - 1];
		}
	}
};