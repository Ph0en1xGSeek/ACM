#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100004

using namespace std;

int dp[2][MAXN] = {0};
int arr[MAXN];

int main() {
    int N, M;
    cin >> N >> M;
    int cnt = 0, cur;
    int n = 0;
    for(int i = 0 ; i < N; ++i) {
        cin >> cur;
        if(cnt > 0) {
            if(cur >= 0) {
                cnt += cur;
            }else {
                arr[n++] = cnt;
                cnt = cur;
            }
        }else if(cnt < 0) {
            if(cur <= 0) {
                cnt += cur;
            }else {
                arr[n++] = cnt;
                cnt = cur;
            }
        }else {
            cnt += cur;
        }
    }
    if(cnt > 0) {
        arr[n++] = cnt;
    }
    N = n;
    int ans = 0;
    if(N <= M) {
        for(int i = 0; i < N; ++i) {
            if(arr[i] > 0) {
                ans += arr[i];
            }
        }
    }else {
        int c, p;
        for(int i = 0; i < M; ++i) {
            int sum = 0;
            c = i & 1;
            p = c ^ 1;
            for(int j = 1; j <= N; ++j) {
                if(sum < dp[p][j-1])
                    sum = dp[p][j-1];
                dp[c][j] = max(sum, dp[c][j-1]) + arr[j-1];
            }
        }
        for(int i = M; i <= N; ++i) {
            if(ans < dp[c][i])
                ans = dp[c][i];
        }
    }
    cout << ans << endl;
    
    return 0;
}