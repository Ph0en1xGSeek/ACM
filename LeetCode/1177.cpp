class Solution {
public:
	vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
		int size = queries.size();
		int s_size = s.size();
		vector<bool> ret(size);
		vector<vector<int>> accu(s_size + 1, vector<int>(26, 0));
		for(int i = 1; i <= s_size; ++i) {
			copy(accu[i-1].begin(), accu[i-1].end(), accu[i].begin());
			++accu[i][s[i-1] - 'a'];
		}
		int odd;
		for(int i = 0; i < size; ++i) {
			odd = 0;
			int from = queries[i][0];
			int to = queries[i][1];
			int k = queries[i][2];
			for(int j = 0; j < 26; ++j) {
				if((accu[to+1][j] - accu[from][j]) & 1) {
					++odd;
				}
			}
			if(odd / 2 > k) {
				ret[i] = false;
			}else {
				ret[i] = true;
			}
		}
		return ret;
	}
};
