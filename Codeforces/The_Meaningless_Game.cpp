#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

map<long long, long long> mp;

int main()
{
    int ca;
    scanf("%d", &ca);
    long long a, b;
    for(long long i = 1; i <= 1e6; i++)
    {
        mp[i*i*i] = i;
    }
    while(ca--)
    {
        scanf("%I64d%I64d", &a, &b);
        if(mp[a*b] != 0 && a % mp[a*b] == 0 && b % mp[a*b] == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
