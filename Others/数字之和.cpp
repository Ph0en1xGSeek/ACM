#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int num;
    int ans1, ans2, tmp;
    while(~scanf("%d", &num) && num != 0)
    {
        ans1 = ans2 = 0;
        tmp = num*num;
        while(num > 0)
        {
            ans1 += num % 10;
            num /= 10;
        }

        while(tmp > 0)
        {
            ans2 += tmp % 10;
            tmp /= 10;
        }

        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
