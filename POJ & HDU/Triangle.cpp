#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#define INF 1000000

using namespace std;

int arr[]={0,0,0,0,1,1,2,3,3,4,5,6,7,7,8,9,10,11,12,13,14};

int main()
{
    int ca, num, cc=1;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        printf("Case #%d: %d\n", cc++, arr[num]);
    }
    return 0;
}
