#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a> b;
}

int main()
{
    int arr[10005];
    int ans = -1;
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+num, cmp);
    for(int i = 0; i < num-3; i++)
    {
        if(arr[i] < arr[i+1] + arr[i+2] + arr[i+3] && (arr[i] != arr[i+1] || (arr[i+1] != arr[i+2] || arr[i+2] != arr[i+3])))
        {

            ans = arr[i] + arr[i+1] + arr[i+2] + arr[i+3];
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
