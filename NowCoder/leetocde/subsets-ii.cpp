class Solution {
public:
	void dfs(vector<int> &s, vector<vector<int>> &res, vector<int> &cur_set, int pos) {
		res.push_back(cur_set);
		for(int i = pos; i < s.size(); ++i) {
			cur_set.push_back(s[i]);
			dfs(s, res, cur_set, i+1);
			cur_set.pop_back();
			while(i+1 < s.size() && s[i] == s[i+1]) {
				++i;
			}
		}
	}
	
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<vector<int> > res;
		vector<int> cur_set;
		dfs(S, res, cur_set, 0);
		return res;
	}
};