#include <iostream>
#include <stdio.h>
#include <cstring>
#define M 100086

using namespace std;
int arr[M], c[M], n;

void add(int bit, int num)
{
    while(bit <= n)
    {
        c[bit] += num;
        bit += bit & (-bit);
    }
}

int getsum(int t)
{
    int sum = 0;
    while(t >= 1)
    {
        sum += c[t];
        t -= t & (-t);
    }
    return sum;
}

int main()
{
    int ca, tmp;
    int a, b;
    char op[10];
    scanf("%d", &ca);
    while(ca--)
    {
        memset(c, 0, sizeof(c));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            add(i, arr[i]);
        }
        scanf("%d", &tmp);
        while(tmp--)
        {
            scanf("%s", op);
            scanf("%d%d", &a, &b);
            if(op[0] == 'I')
                printf("%d\n", getsum(b) - getsum(a-1));
            else if(op[0] == 'A')
            {
                add(a, b);
                arr[a] += b;
            }
            else
            {
                b = min(arr[a], b);
                add(a, -b);
                arr[a] -= b;
            }

        }
    }
    return 0;
}
