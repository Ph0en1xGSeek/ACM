/**Uva 10790 ÿ�����㶼Ҫ�����¸�ѡ2���㣬������a*(a-1)/2��ѡ�� ����ͬ��*/

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
