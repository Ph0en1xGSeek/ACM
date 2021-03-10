#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[10050];

int main()
{
    int n, m;
    int l, r, x;
    int cnt;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for(int i = 0; i < m ; i++)
        {
            cnt = 0;
            scanf("%d%d%d", &l, &r, &x);
            for(int j = l; j <= r; j++)
            {
                if(arr[j] < arr[x]) cnt++;
            }
            if(cnt == x - l) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
