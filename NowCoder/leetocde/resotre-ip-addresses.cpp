class Solution {
public:
	void dfs(vector<string> &ans, int k, string s, string cur) {
		if(k == 4 && s.size() == 0) {
			ans.push_back(cur);
			return;
		}
		if(k == 4 || s.size() == 0) {
			return;
		}
		int pos = 1;
		int num = s[0] - '0';
        int sz = s.size();
		while(pos <= sz && num <= 255) {
            if(k == 0)
			    dfs(ans, k+1, s.substr(pos), s.substr(0, pos));
            else
                dfs(ans, k+1, s.substr(pos), cur + "." + s.substr(0, pos));
            if(s[0] == '0') {
                return;
            }
            num = num * 10 + s[pos] - '0';
            ++pos;
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		dfs(ans, 0, s, "");
		return ans;
	}
};