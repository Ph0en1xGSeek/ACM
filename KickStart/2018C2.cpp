#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int a[16][16];
int b[16][16];
int ans, N;

void dfs(int from, int state, int sum, int mx) {
    if(sum > mx + mx) {
        ++ans;
    }
    while(from < N) {
        if((state & (1 << from)) == 0) {
            for(int i = 1; i <= b[from][0]; ++i) {
                int to = b[from][i];
                if((state & (1 << to)) == 0) {
                    dfs(from + 1, (state | (1 << from) | (1 << to)), sum + a[from][to], max(mx, a[from][to]));
                }
            }
        }
        ++from;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        ans = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                scanf("%d", &a[i][j]);
                if(a[i][j] > 0 && j > i) {
                    b[i][++b[i][0]] = j;
                }
            }
        }
        dfs(0, 0, 0, 0);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}