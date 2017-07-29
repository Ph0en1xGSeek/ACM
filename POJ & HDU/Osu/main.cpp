#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

double mi[55];
int arr[55];

void init()
{
    mi[0] = 1;
    mi[1] = 0.95;
    for(int i = 1; i <= 51; i++)
        mi[i] = mi[i-1] * 0.95;
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    init();
    int ca, num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+num, cmp);
        double ans = 0;
        for(int i = 0; i < num; i++)
            ans += mi[i]*(double)arr[i];
        printf("%.10lf\n", ans);
    }
    return 0;
}
