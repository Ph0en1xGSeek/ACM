class Solution {
public:
	int findIntegers(int num) {
		if(num == 1) {
			return 2;
		}
		int tmp = num;
		vector<int> bit_vec;
		while(tmp > 0) {
			if(tmp & 1) {
				bit_vec.push_back(1);
			}else {
				bit_vec.push_back(0);
			}
            tmp >>= 1;
		}
		int sz = bit_vec.size();
		vector<vector<int>> dp(sz + 1, vector<int>(2, 0));
		dp[1][0] = dp[1][1] = 1;
		for(int i = 2; i <= sz; ++i) {
			dp[i][0] = dp[i-1][0] + dp[i-1][1];
			dp[i][1] = dp[i-1][0];
		}
		int ans = 0;
        int i;
		for(i = sz-1; i >= 0; --i) {
			if(bit_vec[i] == 1) {
				ans += dp[i+1][0];
				if(i != sz-1 && bit_vec[i+1] == 1) {
					break;
				}
			}
		}
        if(i < 0) {
            ++ans;
        }
		return ans;
	}
};