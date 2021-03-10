#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int f[1000010];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        f[0] = f[1] = 1;
        f[2] = 2;
        for(int i = 1; i <= n/2 + 1; i++)
        {
            f[2*i] = (f[i] + f[2*i-2]) % 1000000000;
            f[2*i+1] = f[2*i];
        }
        printf("%d\n", f[n]);
    }
    return 0;
}
