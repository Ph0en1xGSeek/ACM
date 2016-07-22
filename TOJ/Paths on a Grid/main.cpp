#include <iostream>
#include <stdio.h>

using namespace std;

long long c(long long a, long long b)
{
   if(b > a - b) b = a - b;
   long long ans = 1, cou = b;
   while(cou--)
   {
       ans *= a--;
       while(ans % b == 0 && b > 1)
        ans /= b--;
   }
   return ans;
}


int main()
{
    long long n, m;
    while(scanf("%lld%lld", &n, &m) != EOF)
    {
        if(n == 0 && m == 0)    break;
        printf("%lld\n", c(n+m, n));
    }
    return 0;
}
