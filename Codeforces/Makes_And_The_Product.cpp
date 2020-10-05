#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 0x7fffffff

using namespace std;

int miArr[5];
long long cnt[5];
int n;
int arr[100005];
int cur;
long long ans;


int main() {

    while (~scanf("%d", &n))
    {
        cur = 0;
        memset(miArr, 0, sizeof(miArr));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+n);
        miArr[0] = arr[0];
        cnt[0] = 1;
        for(int i = 1; i < n && cur < 3; i++)
        {
            if(arr[i] != arr[i-1])
            {
                cur++;
                miArr[cur] = arr[i];
            }
            cnt[cur]++;
        }

        if(cnt[0] >= 3)
        {
            ans = cnt[0]*(cnt[0]-1)*(cnt[0]-2) / 6;
        }
        else if(cnt[0] + cnt[1] >= 3)
        {
            int tmp = 3 - cnt[0];
            ans = 1;
            for(int i = 0; i < tmp; i++)
            {
                ans *= cnt[1] - i;
            }
            for(int i = 0; i < tmp; i++)
            {
                ans /= i+1;
            }
        }
        else
        {
            int tmp = 3 - cnt[0] - cnt[1];
            ans = 1;
            for(int i = 0; i < tmp; i++)
            {
                ans *= cnt[2] - i;
            }
            for(int i = 0; i < tmp; i++)
            {
                ans /= i+1;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}