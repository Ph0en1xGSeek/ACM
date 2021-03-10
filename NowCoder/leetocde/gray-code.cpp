class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		if(n == 0) {
			return vector<int>(1, 0);
		}
        res.resize((1 << n));
        res[0] = 0;
        res[1] = 1;
		for(int i = 1; i < n; ++i) {
			for(int j = 0; j < (1 << i); ++j) {
				res[(1<< i) + j] = res[(1 << i) - j - 1] + (1 << i);
			}
		}
		return res;
	}
};