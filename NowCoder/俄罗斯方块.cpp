#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> cnt(m, 0);
    int pos;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &pos);
        ++cnt[pos-1];
    }
    int ans = m;
    for(int i = 0; i < n; ++i) {
        ans = min(ans, cnt[i]);
    }
    printf("%d\n", ans);
    return 0;
}