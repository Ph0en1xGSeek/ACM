#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, a, b;
    while(~scanf("%d%d", &n, &m))
    {
        int tmp, ans = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            if(a > b)
                tmp = a - b - 1;
            else
                tmp = b - a - 1;
            ans ^= tmp;
        }
        if(ans)
            puts("I WIN!");
        else
            puts("BAD LUCK!");
    }
    return 0;
}
