#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

double arr[1001][1001];

int main() {
	int n, m;
	while(cin >> n >> m) {
		memset(arr, 0, sizeof(arr));
		for(int i = 1; i <= n; ++i) {
			arr[i][0] = 1.0;
			for(int j = 1; j <= m; ++j) {
				arr[i][j] = (double)i / ((double)i + j);
				if(j > 2) {
					arr[i][j] += ((double)j / (i + j)) * 
								(((double)j - 1.0) / (i + j - 1.0)) * 
								(((double)i / (i + j - 2.0)) * arr[i-1][j-2] + (((double)j - 2.0) / (i + j - 2.0)) * arr[i][j-3]);
				}else if(j == 2) {
					arr[i][j] += ((double)j / (i + j)) * 
								(((double)j - 1.0) / (i + j - 1.0)) * 
								arr[i-1][j-2];
				}
			}
		}
		printf("%.4lf\n", arr[n][m]);
	}
	return 0;
}