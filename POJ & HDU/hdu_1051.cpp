#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct stick{
    int l;
    int w;
    bool operator<(const stick b) const {
        if(l == b.l) {
            return w < b.w;
        }
        return l < b.l;
    }
}stick;

int main() {
    int T;
    scanf("%d", &T);
    vector<stick> sticks;
    vector<bool> flag;
    int cnt;
    while(T--) {
        int n;
        scanf("%d", &n);
        cnt = 0;
        flag.resize(n);
        fill(flag.begin(), flag.end(), false);
        sticks.resize(n);
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &sticks[i].l, &sticks[i].w);
        }
        sort(sticks.begin(), sticks.end());
        int ans = 0;
        while(cnt < n) {
            int cur_l = 0, cur_w = 0;
            for(int i = 0; i < n; ++i) {
                if(flag[i]) continue;
                if(sticks[i].l >= cur_l && sticks[i].w >= cur_w) {
                    cur_l = sticks[i].l;
                    cur_w = sticks[i].w;
                    flag[i] = true;
                    ++cnt;
                }
            }
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}