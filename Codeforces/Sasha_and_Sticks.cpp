#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    long long n, k;
    while(~scanf("%I64d%I64d", &n, &k))
    {
        long long tmp = n / k;
        if (tmp % 2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
