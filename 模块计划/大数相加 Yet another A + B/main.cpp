#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool cmp(int arr1[201], int arr2[201])
{
    for(int i = 0; i < 201; i++)
    {
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}

void make(string n, int a[201])
{
    for(int i = n.length()-1, j = 200; i >= 0; i--, j--)
    {
        a[j] = n[i]-'0';
    }
}

void add(int a[201], int b[201], int c[201])
{
    for(int i = 0; i < 201; i++)  c[i] = 0;
    for(int j = 200; j > 0; j--)
    {
        c[j] += a[j] + b[j];
        c[j-1] += (c[j] / 10);
        c[j] %= 10;
    }
    c[0] += a[0] + b[0];
}

int main()
{
    int a[201], b[201], c[201], d[201], e[201], f[201], g[201];
    int h[201], i[201];

    string num1, num2, num3;
    while(cin >> num1 >> num2 >> num3)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        make(num1, a);
        make(num2, b);
        make(num3, c);
        add(a, b, d);
        add(a, c, e);
        add(b, c, f);
        add(a, a, g);
        add(b, b, h);
        add(c, c, i);
        if(cmp(d, c) || cmp(e, b) || cmp(f, a) || cmp(g, b) || cmp(g, c)
           || cmp(h,a) || cmp(h, c) || cmp(i, a) || cmp(i, b))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
