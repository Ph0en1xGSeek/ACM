#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    int cnt;
    int arr[51];
    int num;
    while(scanf("%d", &num) != 0 && num)
    {
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        for(int i = 0; i < num-1; i++)
            for(int j = i+1; j < num; j++)
                if(gcd(arr[i], arr[j]) == 1)
                    cnt++;
        if(cnt == 0)
            printf("No estimate for this data set.\n");
        else
        {
            int total = num * (num-1) / 2;
            double tmp = (double)cnt / (double)total;
            tmp = 6.0 / tmp;
            tmp = sqrt(tmp);
            printf("%.6f\n", tmp);
        }
    }
    return 0;
}
