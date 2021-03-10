#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n, k;
    while(scanf("%d%d", &n, &k) && n != 0)
    {
        int s = 0;
        for(int i = 2; i <= n; i++)
            s = (s + k) % i;
        printf("%d %d %d\n", n, k, s+1);
    }
    return 0;
}
