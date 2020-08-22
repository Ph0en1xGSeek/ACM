class Solution {
public:
    double soupServings(int N) {
    	N = (N + 24) / 25;
	if(N >= 500) {
		return 1.0;
	}
	vector<vector<double>> memo(N + 1, vector<double>(N + 1, 0));
	for(int s = 0; s <= 2 * N; ++s) {
		for(int i = 0; i <= N; ++i) {
			int j = s - i;
			if(j < 0 || j > N) {
				continue;
			}
			double ans = 0;
			if(i == 0 && j == 0) {
				ans = 0.5;
			}else if(i == 0) {
				ans = 1.0;
			}
			if(i > 0 && j > 0) {
				ans = 0.25 * (memo[max(i - 4, 0)][j] + memo[max(i - 3, 0)][max(j - 1, 0)] + 
                                memo[max(i - 2, 0)][max(j - 2, 0)] + memo[max(i - 1, 0)][max(j - 3, 0)]);
			}
			memo[i][j] = ans;
		}
	}
	return memo[N][N];
    }
};
