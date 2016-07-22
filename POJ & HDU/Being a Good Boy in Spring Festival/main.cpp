#include <iostream>
#include <stdio.h>

using namespace std;
int num[101];

int main()
{
    int n, tmp, ans;
    while(scanf("%d", &n), n)
    {
        ans = tmp = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            tmp = (tmp ^ num[i]);
        }
        if(tmp == 0)
        {
            printf("0\n");
            continue;
        }
        for(int i = 0; i < n; i++)
            if(num[i] > (tmp ^ num[i]))
                ans++;
        printf("%d\n", ans);

    }
    return 0;
}
