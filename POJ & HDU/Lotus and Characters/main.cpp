#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 100

using namespace std;

struct node
{
    int val;
    int cnt;
    bool operator<(node b)
    {
        return val < b.val;
    }
}arr[M];

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        int num;
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%d%d", &arr[i].val, &arr[i].cnt);
        }
        sort(arr, arr+num);
        int pos = 1;
        int ans = 0;
        int tot = 0;
        int positivePos = 0;
        while(arr[positivePos].val < 0 && positivePos < num)
            positivePos++;

        for(int i= positivePos; i < num; i++)
        {
            tot += arr[i].val*arr[i].cnt;
        }
        int i;
        for(i = positivePos-1; i >= 0; i--)
        {
            if(tot + arr[i].val*arr[i].cnt > 0)
                tot += arr[i].val*arr[i].cnt;
            else
                break;
        }
        if(i >= 0)
        {
            arr[i].cnt = -tot/arr[i].val;

        }
        else
            i = 0;
        for(; i < num; i++)
        {
            for(int j = 0; j < arr[i].cnt; j++)
            {
                ans += arr[i].val * pos;
                pos++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
