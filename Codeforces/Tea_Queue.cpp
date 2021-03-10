#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int t;
    int cur = 0;
    int num;
    int l, r;
    int arr[1005];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &num);
        cur = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d%d", &l, &r);
            if(l <= cur)
            {
                if(cur >= r)
                    arr[i] = 0;
                else
                {
                    arr[i] = ++cur;
                }
            }
            else
            {
                cur = l;
                arr[i] = l;
            }
        }
        for(int i = 0; i < num; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
