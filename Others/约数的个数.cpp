#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[100000];
int cnt;

int main()
{
    int n;
    int tmp;
    while(~scanf("%d", &n) && n != 0)
    {
        for(int i = 0; i < n; i++)
        {
            cnt = 0;
            scanf("%d", &tmp);
            if(tmp == 1)
            {
                printf("1\n");
            }
            else
            {
                arr[0] = 0;
                for(int i = 2; i < 40000; i++)
                {
                    if(tmp % i == 0)
                    {
                        while(tmp%i == 0)
                        {
                            tmp /= i;
                            arr[cnt]++;
                        }
                        cnt++;
                        arr[cnt] = 0;
                        if(tmp == 1)
                            break;
                    }
                }
                if(tmp != 1)
                    arr[cnt++] = 1;
                int ans = 1;
                for(int i = 0; i < cnt; i++)
                    ans *= (arr[i]+1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
