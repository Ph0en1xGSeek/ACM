#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#define N 100


using namespace std;

const long long max_p = 1e18;
vector<pair<int, int>> limits[N+1];
long long dp[N+1][1<<16];
int cnt[1<<16];
int shl[1<<16];

bool check(int pos, int status) {
    for(int i = 0; i < limits[pos].size(); ++i) {
        if(cnt[status & ((1 << limits[pos][i].first) - 1)] != limits[pos][i].second) {
            return false;
        }
    }
    return true;
}


int main() {
    cnt[0] = 0;
    shl[0] = 0;
    for(int i = 1; i < (1<<16); ++i) {
        cnt[i] = cnt[i>>1] + (i & 1);
        shl[i] = (i << 1) & ((1 << 16) - 1);
    }

    int t, n, k, a, b, c;
    long long p;
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ++ca) {
        scanf("%d%d%lld", &n, &k, &p);
        for(int i = 1; i <= n; ++i) {
            limits[i].clear();
        }
        for(int i = 0; i < k; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            limits[b].push_back(make_pair(b-a+1, c));
        }
        memset(dp, 0, sizeof(dp));
        for(int j = 0; j < (1<<16); ++j) {
            if(check(n, j)) {
                dp[n][j] = 1;
            }
        }
        for(int i = n-1; i >= 1; --i) {
            for(int j = 0; j < (1<<16); ++j) {
                if(check(i, j)) {
                    dp[i][j] = dp[i+1][shl[j]] + dp[i+1][shl[j] ^ 1];
                    if(dp[i][j] > max_p) {
                        dp[i][j] = max_p+1;
                    }
                }
            }
        }

        printf("Case #%d: ", ca);
        for(int i = 1, j = 0; i <= n; ++i, j = shl[j]) {
            if(dp[i][j] >= p) {
                printf("0");
            }else {
                p -= dp[i][j];
                j ^= 1;
                printf("1");
            }
        }
        printf("\n");

    }
    return 0;
}