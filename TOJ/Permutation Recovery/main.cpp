#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int arr[505];
    int r[505];
    int num, cnt;
    while(scanf("%d", &num) && num != 0)
    {
        memset(arr, 0, sizeof(arr));
        for(int i = 1; i <= num; i++)
            scanf("%d", &r[i]);
        for(int i = 1; i <= num; i++)
        {
            cnt = 0;
            int j;
            for(j = 1; cnt <= r[i]; j++)
            {
                if(arr[j] == 0)
                    cnt++;
            }
            arr[j-1] = i;
        }
        printf("%d", arr[1]);
        for(int i = 2; i <= num; i++)
            printf(",%d", arr[i]);
        printf("\n");
    }
    return 0;
}
