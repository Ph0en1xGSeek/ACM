#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long ca, num, left, right, mid;
    scanf("%lld", &ca);
    while(ca--)
    {
        scanf("%lld", &num);
        left = 0;
        right = 100000;
        while(left < right)
        {
            mid = (left + right) / 2;
            if((mid * (mid +1)) / 2 < num)
                left = mid + 1;
            else
                right = mid;
        }
        printf("%d\n", right);
    }
    return 0;
}
