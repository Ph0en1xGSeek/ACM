#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int k;
char str[100010];
int arr[100010];

int main()
{
    while(~scanf("%d", &k))
    {
        scanf("%s", str);
        int cnt = 0;
        for(int i = 0 ; i < strlen(str); i++)
        {
            arr[i] = str[i] - '0';
            cnt += arr[i];
        }
        if(cnt >= k)
            printf("0\n");
        else
        {
            sort(arr, arr + strlen(str));
            int sum = 0;
            for(int i = 0; i < strlen(str); i++)
            {
                sum++;
                cnt += 9 - arr[i];
                if(cnt >= k) break;
            }
            if(cnt < k)
                sum += (k - cnt) / 9 + 1;
            printf("%d\n", sum);
        }
    }


    return 0;
}
