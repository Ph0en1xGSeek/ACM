#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#define N 1000
#define M 10000

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)  return a;
    return gcd(b, a%b);
}

int main()
{
    int num;
    int t[N], r[N];
    int c[M];
    while(scanf("%d", &num) != EOF)
    {
        for(int i = 0; i < num; i++)  scanf("%d", &t[i]);
        memset(c, 0, sizeof(c));
        memset(r, 0, sizeof(r));
        r[0] = 1;
        int d = 0, a, b, g, k;
        for(int i = 1; i < num; i++)
            if(t[i] != t[0])
            {
                b = t[i] * t[0];
                a = (abs(t[i] - t[0]) << 1);
                g = gcd(a, b);
                a /= g;
                b /= g;
                d = gcd(a, d);

                for(int j = 2; b > 1; j++)
                {
                    k = 0;
                    while(b % j == 0)
                    {
                        b /= j;
                        k++;
                    }
                    if(k > c[j])
                        c[j] = k;
                }
            }
            int tmp;
            for(int i = 0; i < M; i++)
            {
                for(int j = 0; j < c[i]; j++)
                {
                    tmp = 0;
                    for(k = 0; k < N; k++)
                    {
                        r[k] = r[k]*i + tmp;
                        tmp = r[k] / M;
                        r[k] %= M;
                    }
                }
            }
            int i = 999;
            while(i && r[i] == 0)
                i--;
            printf("%d", r[i]);
            for(--i; i >= 0; i--)
                printf("%04d", r[i]);
            printf(" %d\n", d);
    }

    return 0;
}
