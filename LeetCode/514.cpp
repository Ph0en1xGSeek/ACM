class Solution {
public:
	int findRotateSteps(string ring, string key) {
		int ring_sz = ring.size();
		int key_sz = key.size();
		vector<vector<int> >dp(key_sz + 1, vector<int>(ring_sz, 0));
		for(int i = key_sz-1; i >= 0; --i) {
			for(int j = 0; j < ring_sz; ++j) {
				dp[i][j] = INT_MAX;
				for(int k = 0; k < ring_sz; ++k) {
					if(ring[k] != key[i]) continue;
					int step = k - j > 0? k - j : j - k;
					step = min(step, ring_sz - step);
					dp[i][j] = min(dp[i][j], dp[i+1][k] + step);
				}
			}
		}
		return dp[0][0]  + key_sz;
	}
};