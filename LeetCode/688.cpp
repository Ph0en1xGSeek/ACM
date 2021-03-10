class Solution {
public:
	double knightProbability(int N, int K, int r, int c) {
		vector<vector<vector<double>> > board(2, vector(N, vector<double>(N)));
		int cur = 1;
		board[cur][r][c] = 1;
		for(int k = 0; k < K; ++k) {
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    board[1-cur][i][j] = 0;
                }
            }
			for(int i = 0; i < N; ++i) {
				for(int j = 0; j < N; ++j) {
					for(int d = 0; d < 8; ++d) {
						int new_x = i + dir[d][0];
						int new_y = j + dir[d][1];
						if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
							board[1-cur][new_x][new_y] += board[cur][i][j] / 8;
						}
					}
				}
			}
			cur = 1 - cur;
		}
		double sum = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				sum += board[cur][i][j];			}
		}
		return sum;
	}
private:
	int dir[8][2] = {1,2,-1,2,1,-2,-1,-2,2,1,-2,1,2,-1,-2,-1};
};