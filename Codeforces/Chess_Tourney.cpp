#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[500];

int main()
{
    int n;
    while(~scanf("%d%", &n))
    {
        for(int i = 0; i < 2*n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+n*2);
        if(arr[n-1] < arr[n])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
