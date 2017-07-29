#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int arr[105];
    int ca;
    int m, n;
    int a, b;
    int sum;
    scanf("%d", &ca);
    while(ca--)
    {
        sum = 0;
        memset(arr, 0, sizeof(arr));
        scanf("%d%d", &m, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            arr[a] = b;
        }
        int tmp = 0;
        for(int i = m; i >= 3; i--)
        {
            if(arr[i] == 0)
            {
                arr[i] = tmp;
                sum += tmp;
            }
            else
            {
                tmp = arr[i];
                sum += tmp;
            }
        }

        if(arr[1] && !arr[2])
        {
            arr[2] = arr[1];
            sum += (arr[2] + arr[1]);
        }
        else if(!arr[2] && !arr[1])
        {
            arr[1] = arr[2] = 100;
            sum += 200;
        }
        else if(!arr[1] && arr[2])
        {
            arr[1] = 100;
            sum += arr[2] + arr[1];
        }
        else
            sum += arr[1] + arr[2];
        int fenzi = arr[1] + arr[2];
        int gcd = __gcd(sum, fenzi);
        printf("%d/%d\n", fenzi/gcd, sum/gcd);

    }
    return 0;
}
