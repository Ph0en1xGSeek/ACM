#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 200010

using namespace std;

int cnt[M];
int cum[M];


int main() {

    int n, k, q;
    int l, r;
    int tmp;
    int mxL;
    cum[0] = 0;
    while (scanf("%d%d%d", &n, &k, &q) != EOF)
    {
        mxL = 0;
        tmp = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &l, &r);
            cnt[l]++;
            cnt[r+1]--;
//            mxL = max(mxL, r);
        }
        for(int i = 1; i <= M; i++)
        {
            cnt[i] += cnt[i-1];
            if(cnt[i] >= k) tmp++;
            cum[i] = tmp;
        }
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", cum[r]-cum[l-1]);
        }
    }
    return 0;
}