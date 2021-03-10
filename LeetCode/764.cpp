class Solution {
public:
	int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
		if(N == 0) {
			return 0;
		}
		vector<vector<bool>> arr(N, vector<bool>(N, true));
		int size = mines.size();
		for(int i = 0; i < size; ++i) {
			arr[mines[i][0]][mines[i][1]] = false;
		}
		vector<vector<int>> dp_l(N, vector<int>(N, 0));
		vector<vector<int>> dp_r(N, vector<int>(N, 0));
		vector<vector<int>> dp_u(N, vector<int>(N, 0));
		vector<vector<int>> dp_d(N, vector<int>(N, 0));
		for(int i = 0; i < N; ++i) {
			dp_l[i][0] = arr[i][0]? 1: 0;
			for(int j = 1; j < N; ++j) {
				if(arr[i][j] == 0) {
					dp_l[i][j] = 0;
				}else {
					dp_l[i][j] = dp_l[i][j-1] + 1;
				}
			}
			dp_r[i][N-1] = arr[i][N-1] ? 1: 0;
			for(int j = N-2; j >= 0; --j) {
				if(arr[i][j] == 0) {
					dp_r[i][j] = 0;
				}else {
					dp_r[i][j] = dp_r[i][j+1] + 1;
				}
			}
		}
		for(int j = 0; j < N; ++j) {
			dp_u[0][j] = arr[0][j] ? 1: 0;
			for(int i = 1; i < N; ++i) {
				if(arr[i][j] == 0) {
					dp_u[i][j] = 0;
				}else {
					dp_u[i][j] = dp_u[i-1][j] + 1;
				}
			}
			dp_d[N-1][j] = arr[N-1][j] ? 1: 0;
			for(int i = N-2; i >= 0; --i) {
				if(arr[i][j] == 0) {
					dp_d[i][j] = 0;
				}else {
					dp_d[i][j] = dp_d[i+1][j] + 1;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				int tmp = min(dp_l[i][j], dp_r[i][j]);
				tmp = min(tmp, dp_u[i][j]);
				tmp = min(tmp, dp_d[i][j]);
				ans = max(ans, tmp);
			}
		}
		return ans;
	}
};
