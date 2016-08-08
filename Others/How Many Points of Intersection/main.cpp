/**Uva 10790 每个交点都要在上下各选2个点，上面有a*(a-1)/2种选法 下面同理*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long a, b;
    int ca = 1;
    while(~scanf("%lld%lld", &a, &b) && a != 0 && b != 0)
    {
        printf("Case %d: %lld\n", ca++, a*(a-1)*b*(b-1)/4);
    }
    return 0;
}
