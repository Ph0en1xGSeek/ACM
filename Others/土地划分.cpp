#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int w, h, ans;
    int x[55], y[55];
    while(scanf("%d%d", &w, &h) && w)
    {
        ans = 0;
        int num;
        scanf("%d", &num);
        for(int i = 0; i <= num; i++)
            scanf("%d%d", &x[i], &y[i]);
        if(num < 3)
        {
            printf("%d\n", num+1);
        }
        else
        {
            for(int i = 3; i <= num; i++)
            {
                for(int j = i-2; j > 0; j--)
                {
                    int d1 = (x[i-1]-x[j-1])*(y[j]-y[j-1]) - (y[i-1]-y[j-1])*(x[j]-x[j-1]);
                    int d2 = (x[i]-x[j-1])*(y[j]-y[j-1]) - (y[i]-y[j-1])*(x[j]-x[j-1]);
                    if(d1 * d2 < 0)
                        ans++;
                }
            }
            printf("%d\n", num+1+ans);
        }
    }
    return 0;
}
