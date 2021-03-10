#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    __int64 arr[3];
    bool flag = false;
    while(scanf("%I64d%I64d%I64d", &arr[0], &arr[1], &arr[2]) != EOF)
    {
        flag = false;
        sort(arr, arr+3);
        do
        {
            if(arr[0] + arr[1] == arr[2])
            {
                flag = true;
                break;
            }
            if(arr[0] * arr[1] == arr[2])
            {
                flag = true;
                break;
            }
            if(arr[1] != 0 && arr[0] % arr[1] == arr[2])
            {
                flag = true;
                break;
            }
        }while(next_permutation(arr, arr+3));

        if(flag)
            printf("oh,lucky!\n");
        else
            printf("what a pity!\n");
    }
    return 0;
}
