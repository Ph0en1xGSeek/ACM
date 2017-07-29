#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int ca, num, tmp;
    int ans;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d", &num);
        while(num--)
        {
            scanf("%d", &tmp);
            if(tmp == 1)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
