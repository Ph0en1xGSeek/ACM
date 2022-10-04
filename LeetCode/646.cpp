class Solution {
public:
	int findLongestChain(vector<vector<int>> &pairs) {
		int sz = pairs.size();
		if(sz == 0) {
			return 0;
		}
		sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) -> bool {
			if(a[1] == b[1]) {
				return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        int ans = 1;
        int tmp_right = pairs[0][1];
        for(int i = 1; i < sz; ++i) {
            if(pairs[i][0] > tmp_right) {
                ++ans;
                tmp_right = pairs[i][1];
            }
        }
        return ans;
	}
};