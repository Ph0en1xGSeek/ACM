#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {

    int n, m;
    char s[1005], t[1005];
    int q[1005];
    int top;
    int pos;
    int mi;
    int cnt;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        top = 0;
        pos = 0;
        mi = 10000000;
        scanf("%s %s", s, t);
        for(int i = 0; i <= m-n; i++)
        {
            cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(t[i+j] != s[j])
                    cnt++;
            }
            if(cnt < mi)
            {
                mi = cnt;
                pos = i;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(t[pos + i] != s[i])
                q[top++] = i+1;
        }

        printf("%d\n", mi);
        if(mi > 0)
            printf("%d", q[0]);
        for(int i = 1; i < mi; i++)
        {
            printf(" %d", q[i]);
        }
        printf("\n");
    }
    return 0;
}