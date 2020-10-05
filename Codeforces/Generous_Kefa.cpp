#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n, k;
    int arr[30];
    char str[200];
    bool flag;
    while(~scanf("%d%d", &n, &k))
    {
        flag = false;
        memset(arr, 0, sizeof(arr));
        scanf("%s", str);
        for(int i = 0; i < n; i++)
        {
            arr[str[i] - 'a']++;
            if(arr[str[i] - 'a'] > k)
                flag = true;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
