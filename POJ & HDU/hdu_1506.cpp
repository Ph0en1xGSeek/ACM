#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define M 100005

using namespace std;

int arr[M];
int l[M];
int r[M];

int main()
{
    int num;
    while(~scanf("%d", &num) && num != 0)
    {
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
        }
        l[0] = -1;
        for(int i = 1; i < num; i++)
        {
            l[i] = i-1;
            while(arr[l[i]] >= arr[i] && l[i] >= 0)
            {
                l[i] = l[l[i]];
            }
        }
        r[num-1] = num;
        for(int i = num-2; i >= 0; i--)
        {
            r[i] = i+1;
            while(arr[r[i]] >= arr[i] && r[i] < num)
            {
                r[i] = r[r[i]];
            }
        }
        long long ans = 0;
        for(int i = 0; i < num; i++)
        {
            long long tmp = (long long)arr[i] * (r[i] - l[i] - 1);
//            cout << i << ' ' << l[i] << "    " << r[i] << endl;
            ans = max(ans, tmp);
        }

        printf("%I64d\n", ans);
    }
    return 0;
}
