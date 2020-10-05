#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int arr[1005];
    int ca, num;
    char ch;
    int a ,b;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < num; i++)
        {
            getchar();
            scanf("%c%d%d", &ch, &a, &b);
            arr[a]++, arr[b]--;
        }
        int sum = 0;
        for(int i = 0; i <= 1000; i++)
        {
            sum += arr[i];
            if(sum > 0)
                printf("%c", 'A'+sum-1);
        }
        printf("\n");
    }
    return 0;
}
