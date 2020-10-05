#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int arr[35];
    arr[0] = 1;
    arr[2] = 3;
    arr[1] = 0;
    for(int i = 3; i <= 30; i++)
    {
        if(i&1)
            arr[i] = 0;
        else
            arr[i] = 4 * arr[i-2] - arr[i-4];
    }

    int num;
    while(scanf("%d", &num) && num != -1)
        printf("%d\n", arr[num]);
    return 0;
}
