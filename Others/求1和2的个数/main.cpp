#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define mod 20123

using namespace std;

char str[150];

int main()
{
    int result, cnt, num;
    while(~scanf("%s", str))
    {
        int len = strlen(str);
        result = cnt = num = 0;
        for(int i = 0; i < len; i++)
        {
            int t = str[i] - '0';
            result = ((result - cnt) * 10 % mod + cnt * (t+1) % mod + min(t, 2) + num * 2 % mod) % mod;

            if(t == 1 || t == 2)
                cnt++;
            num = ((num * 10) % mod + t) % mod;

        }
        printf("%d\n", result);
    }
    return 0;
}
