#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

int cnt[1000005];


int main() {

    int n, A;
    int tmp;
    while (scanf("%d%d", &n, &A) != EOF)
    {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);

            if(tmp == A)
            {
                cnt[tmp]++;
            }
            else if(cnt[tmp] >= cnt[A])
                cnt[tmp]++;
        }
        int i;
        for(i = 1; i <= 1000000; i++)
            if(cnt[i] >= cnt[A] && i != A)
            {
                printf("%d\n", i);
                break;
            }
        if(i > 1000000)
            printf("-1\n");
    }
    return 0;
}