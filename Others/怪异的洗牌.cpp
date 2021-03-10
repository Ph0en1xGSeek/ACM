#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n, k;
    int pos;
    int arr[1005];
    int arr2[1005];
    int cnt;
    int num;
    int *a, *b;
    while(scanf("%d%d", &n, &k) && n != 0)
    {
        for(int i = 1; i <= n; i++)
            arr[i] = i;
        for(int j = 0; j < k; j++)
        {
            if(j % 2 == 0)
            {
                a = arr;
                b = arr2;
            }
            else
            {
                a = arr2;
                b = arr;
            }
            cnt = 1;
            scanf("%d", &num);
            if(n%2 == 0)
            {
                if((n-num) >= n/2)
                {
                    for(int i = num + n/2; i > num; i--)
                        b[cnt++] = a[i];
                    for(int i = num + n/2 + 1; i <= n; i++)
                        b[cnt++] = a[i];
                    for(int i = 1; i <= num; i++)
                        b[cnt++] = a[i];
                }
                else
                {
                    for(int i = n/2 - (n-num); i >= 1; i--)
                        b[cnt++] = a[i];
                    for(int i = n; i > num; i--)
                        b[cnt++] = a[i];
                    for(int i = n/2 - (n-num) + 1; i <= num; i++)
                        b[cnt++] = a[i];
                }
            }
            else
            {
                if((n-num) >= (n-1)/2)
                {
                    for(int i = num + (n-1)/2; i > num; i--)
                        b[cnt++] = a[i];
                    for(int i = num + (n-1)/2 + 1; i <= n; i++)
                        b[cnt++] = a[i];
                    for(int i = 1; i <= num; i++)
                        b[cnt++] = a[i];
                }
                else
                {
                    for(int i = (n-1)/2 - (n-num); i >= 1; i--)
                        b[cnt++] = a[i];
                    for(int i = n; i > num; i--)
                        b[cnt++] = a[i];
                    for(int i = (n-1)/2 - (n-num) + 1; i <= num; i++)
                        b[cnt++] = a[i];
                }
            }
        }
        if(k % 2 == 1)
            a = arr2;
        else
            a = arr;
        for(int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        printf("\n");

    }
    return 0;
}
