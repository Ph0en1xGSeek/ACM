#include <iostream>
#include <stdio.h>

using namespace std;

int arr1[1000001];
int arr2[1000001];

int main()
{
    int ca;
    scanf("%d", &ca);
    int num;
    while(ca--)
    {
        scanf("%d", &num);
        for(int i = 1; i <= num; i++)
            scanf("%d", &arr1[i]);
        for(int i = 1; i <= num; i++)
            scanf("%d", &arr2[i]);
        arr1[2] += arr1[1];
        arr2[2] += arr2[1];
        for(int i = 3; i <= num; i++)
        {
            arr1[i] += max(arr1[i-1], arr2[i-2]);
            arr2[i] += max(arr2[i-1], arr1[i-2]);
        }
        printf("%d\n", max(arr1[num], arr2[num]));
    }
    return 0;
}
