class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> tmp(k + 1);
		vector<vector<int>> ans;
		for (int i = 1; i <= k; ++i) {
			tmp[i - 1] = i;
		}
		tmp[k] = n + 1;
		
		int j = 0;
		while (j < k) {
			ans.emplace_back(tmp.begin(), tmp.begin() + k);
			j = 0;
			while (j < k && tmp[j] + 1 == tmp[j + 1]) {
				tmp[j] = j + 1;
				++j;
			}
			++tmp[j];
		}
		return ans;
	}
};
