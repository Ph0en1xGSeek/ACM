#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;


int main() {
    int n, w, p, m, c, v;
    vector<int> dp, tmp;
    while(~scanf("%d%d", &n, &w)) {
        dp.resize(w+1, 0);
        fill(dp.begin(), dp.end(), 0);
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &p, &m);
            
            tmp.resize(w+1, 0);
            for(int j = 0; j < p; ++j) {
                tmp[j] = -1;
            }
            for(int j = p; j <= w; ++j) {
                tmp[j] = dp[j-p];
            }
            for(int j = 0; j < m; ++j) {
                scanf("%d%d", &c, &v);
                for(int k = w; k >= p+c; --k) {
                    tmp[k] = max(tmp[k], tmp[k-c] + v);
                }
            }
            for(int j = 0; j <= w; ++j) {
                dp[j] = max(dp[j], tmp[j]);
            }
        }
        printf("%d\n", dp[w]);
    }
    
    return 0;
}


