#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long sum;
    int ca, num;
    long long n, mx;
    scanf("%d", &ca);
    while(ca--)
    {
        mx = 0;
        sum = 0;
        scanf("%d", &num);
        while(num--)
        {
            scanf("%I64d", &n);
            if(n >= mx)
                mx = n;
            sum += n;
        }
        if(sum - mx + 1 >= mx) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
