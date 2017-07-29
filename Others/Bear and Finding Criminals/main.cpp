#include <iostream>
#include <stdio.h>

using namespace std;

int arr[105];

int main()
{
    int n, a;
    int ans;
    while(scanf("%d%d", &n, &a) != EOF)
    {
        ans = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        a--;
        int i;
        for(i = 0; a-i >= 0 && a+i <n; i++)
        {
            if(arr[a-i] & arr[a+i])
            {
                if(i == 0)
                    ans++;
                else
                    ans += 2;
            }
        }

        if(a-i >= 0)
        {
            for(; a-i >= 0; i++)
                if(arr[a-i])
                    ans++;
        }
        if(a+i < n)
        {
            for(; a+i < n; i++)
                if(arr[a+i])
                    ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
