#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    unsigned long long n, m;
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%I64u%I64u", &n, &m);
        int ans = 0;
        while(n != m)
        {
            if(m % n != 0)///n��������������������m��С
            {
                printf("-1\n");
                break;
            }
            unsigned long long gcd = __gcd(m/n, n);///����ܲ������
            if(gcd == 1)///����������ͬ�����޷�����
            {
                printf("-1\n");
                break;
            }
            n *= gcd;///����
            ans++;
        }
        if(n == m)
            printf("%d\n", ans);
    }
    return 0;
}
