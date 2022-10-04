class Solution {
public:
	int findLength(vector<int> &A, vector<int> &B) {
		int sizeA = A.size();
		int sizeB = B.size();
		int ans = 0;
		vector<int> dp(sizeB+1, 0);
		for(int i = 1; i <= sizeA; ++i) {
			for(int j = sizeB; j >= 1; --j) {
				if(A[i-1] == B[j-1]) {
					dp[j] = dp[j-1] + 1;
					ans = max(ans, dp[j]);
                }else {
                    dp[j] = 0;
                }
			}
		}
		return ans;
	}
};
