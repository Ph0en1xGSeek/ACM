#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int arr[7];
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        for(int i = 0; i < 5; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr + 5);
        printf("%d\n", arr[3] * arr[4]);
    }
    return 0;
}
